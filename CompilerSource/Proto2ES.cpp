/** Copyright (C) 2018 Robert B. Colton
***
*** This file is a part of the ENIGMA Development Environment.
***
*** ENIGMA is free software: you can redistribute it and/or modify it under the
*** terms of the GNU General Public License as published by the Free Software
*** Foundation, version 3 of the license or any later version.
***
*** This application and its source code is distributed AS-IS, WITHOUT ANY
*** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
*** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
*** details.
***
*** You should have received a copy of the GNU General Public License along
*** with this code. If not, see <http://www.gnu.org/licenses/>
**/

#include "Proto2ES.h"

#include <unordered_map>
#include <vector>

Sprite AddSprite(const buffers::resources::Sprite& spr);
SubImage AddSubImage(const std::string fPath);
Sound AddSound(const buffers::resources::Sound& snd);
Background AddBackground(const buffers::resources::Background& bkg);
Path AddPath(const buffers::resources::Path& pth);
PathPoint AddPathPoint(const buffers::resources::Path::Point& pnt);
Script AddScript(const buffers::resources::Script& scr);
Shader AddShader(const buffers::resources::Shader& shr);
Font AddFont(const buffers::resources::Font& fnt);
Timeline AddTimeline(buffers::resources::Timeline* tml, buffers::Project* protobuf);
GmObject AddObject(buffers::resources::Object* obj, buffers::Project* protobuf);
Room AddRoom(const buffers::resources::Room& rmn, buffers::Project* protobuf);
Instance AddInstance(const buffers::resources::Room::Instance& inst, buffers::Project* protobuf);
Tile AddTile(const buffers::resources::Room::Tile& tile, buffers::Project* protobuf);
View AddView(const buffers::resources::Room::View& view, buffers::Project* protobuf);
BackgroundDef AddRoomBackground(const buffers::resources::Room::Background& bkg, buffers::Project* protobuf);

template <class T>
int Name2Id(const ::google::protobuf::RepeatedPtrField< T >& group, std::string name) {
  for (auto& message : group) {
    const google::protobuf::Descriptor *desc = message.GetDescriptor();
    const google::protobuf::Reflection *refl = message.GetReflection();

    const google::protobuf::FieldDescriptor *nameField = desc->FindFieldByName("name");
    if (refl->GetString(message, nameField) == name) {
      const google::protobuf::FieldDescriptor *idField = desc->FindFieldByName("id");
      return refl->GetInt32(message, idField);
    }
  }
  return -1;
}

inline std::string string_replace_all(std::string str, std::string substr, std::string nstr)
{
  size_t pos = 0;
  while ((pos = str.find(substr, pos)) != std::string::npos)
  {
    str.replace(pos, substr.length(), nstr);
    pos += nstr.length();
  }
  return str;
}

std::string Argument2Code(const buffers::resources::Argument& arg) {
  using buffers::resources::ArgumentKind;
  std::string val = arg.string();

  if (val.length() == 0) {
    if (arg.kind() == ArgumentKind::ARG_STRING)
      return "\"\"";
    else
      return "0";
  }
  switch (arg.kind()) {
    case ArgumentKind::ARG_BOTH:
      // treat as literal if starts with quote (")
      if (val[0] == '"' || val[0] == '\'') return val;
      // else fall through
    case ArgumentKind::ARG_STRING:
      return '\"' + string_replace_all(string_replace_all(val, "\\", "\\\\"), "\"", "\"+'\"'+\"") + '\"';
    case ArgumentKind::ARG_BOOLEAN:
      return std::to_string(val != "0");
    case ArgumentKind::ARG_MENU:
    case ArgumentKind::ARG_COLOR:
      return val;
    default:
      return val; // TODO: fix oneof <background> <sprite> etc
  }
}

std::string Actions2Code(const ::google::protobuf::RepeatedPtrField< buffers::resources::Action >& actions) {
  using buffers::resources::ActionKind;
  using buffers::resources::ActionExecution;
  std::string code = "";

  int numberOfBraces = 0; // gm ignores brace actions which are in the wrong place or missing
  int numberOfIfs = 0; // gm allows multipe else actions after 1 if, so its important to track the number

  for (const auto &action : actions) {
    const auto &args = action.arguments();

    bool in_with = action.use_apply_to() && action.who_name() != "self";
    if (in_with)
      code += "with (" + action.who_name() + ")\n";

    switch (action.kind()) {
      case ActionKind::ACT_BEGIN:
        code += '{';
        numberOfBraces++;
        break;
      case ActionKind::ACT_END:
        if (numberOfBraces > 0) {
          code += '}';
          numberOfBraces--;
        }
        break;
      case ActionKind::ACT_ELSE:
        if (numberOfIfs > 0) {
          code += "else ";
          numberOfIfs--;
        }
        break;
      case ActionKind::ACT_EXIT:
        code += "exit;";
        break;
      case ActionKind::ACT_REPEAT:
        code += "repeat (" + args.Get(0).string() + ")";
        break;
      case ActionKind::ACT_VARIABLE:
        code += args.Get(0).string();
        if (action.relative())
          code += " += ";
        else
          code += " = ";
        code += args.Get(1).string();
        break;
      case ActionKind::ACT_CODE:
        code += "{\n" + args.Get(0).string() + "\n/**/\n}";
        break;
      case ActionKind::ACT_NORMAL:
        if (action.exe_type() == ActionExecution::EXEC_NONE) break;

        if (action.is_question()) {
          code += "__if__ = ";
          numberOfIfs++;
        }

        if (action.is_not())
          code += "!";

        if (action.relative()) {
          if (action.is_question())
            code += "(argument_relative = " + std::to_string(action.relative()) + ", ";
          else
            code += "{\nargument_relative = " + std::to_string(action.relative()) + ";\n";
        }

        if (action.is_question() && action.exe_type() == ActionExecution::EXEC_CODE)
          code += action.code_string();
        else
          code += action.function_name();

        if (action.exe_type() == ActionExecution::EXEC_FUNCTION) {
          code += '(';
          for (int i = 0; i < args.size(); i++) {
            if (i != 0)
              code += ',';
            code += Argument2Code(args.Get(i));
          }
          code += ')';
        }

        if (action.relative())
          code += action.is_question() ? ");" : "\n}";
        if (action.is_question()) {
          code += "\nif (__if__)";
        }
        break;
      default:
        break;
    }
    code += '\n';
  }

  // someone forgot the closing block action
  if (numberOfBraces > 0)
    for (int i = 0; i < numberOfBraces; i++)
      code += "\n}";

  if (numberOfIfs > 0)
    code = "var __if__ = false;\n" + code;

  return code;
}

#include "lodepng.h"

inline unsigned int nlpo2dc(unsigned int x)  // Taking x, returns n such that n = 2**k where k is an integer and n >= x.
{
  --x;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  return x | (x >> 16);
}

#include <zlib.h>

unsigned char* zlib_compress(unsigned char* inbuffer,int actualsize)
{
    uLongf outsize=(int)(actualsize*1.1)+12;
    Bytef* outbytef=new Bytef[outsize];

    compress(outbytef,&outsize,(Bytef*)inbuffer,actualsize);

    return (unsigned char*)outbytef;
}

Image AddImage(const std::string fname) {
  Image i = Image();

  unsigned error;
  unsigned char* image;
  unsigned pngwidth, pngheight;

  error = lodepng_decode32_file(&image, &pngwidth, &pngheight, fname.c_str());
  if (error)
  {
    printf("error %u: %s\n", error, lodepng_error_text(error));
    return i;
  }

  unsigned
    widfull = nlpo2dc(pngwidth) + 1,
    hgtfull = nlpo2dc(pngheight) + 1,
    ih,iw;
  const int bitmap_size = widfull*hgtfull*4;
  unsigned char* bitmap = new unsigned char[bitmap_size](); // Initialize to zero.

  for (ih = 0; ih < pngheight; ih++) {
    unsigned tmp = ih*widfull*4;
    for (iw = 0; iw < pngwidth; iw++) {
      bitmap[tmp+0] = image[4*pngwidth*ih+iw*4+2];
      bitmap[tmp+1] = image[4*pngwidth*ih+iw*4+1];
      bitmap[tmp+2] = image[4*pngwidth*ih+iw*4+0];
      bitmap[tmp+3] = image[4*pngwidth*ih+iw*4+3];
      tmp+=4;
    }
  }

  free(image);
  i.width  = widfull;
  i.height = hgtfull;
  i.data = reinterpret_cast<char*>(zlib_compress(bitmap, bitmap_size));
  i.dataSize = bitmap_size;

  return i;
}

EnigmaStruct* ProtoBuf2ES(buffers::Project* protobuf) {
  EnigmaStruct *es = new EnigmaStruct();

  es->gameSettings.gameIcon = "";
  es->gameSettings.letEscEndGame = true;
  es->gameSettings.letF4SwitchFullscreen = true;
  es->gameSettings.treatCloseAsEscape = true;
  es->gameSettings.alwaysOnTop = true;
  es->gameSettings.gameId = 0;
  es->gameSettings.company = "";
  es->gameSettings.description = "";
  es->gameSettings.version = "";
  es->gameSettings.product = "";
  es->gameSettings.version = "";
  es->gameSettings.copyright = "";
  es->gameInfo.gameInfoStr = "";
  es->gameInfo.formCaption = "";

  es->spriteCount = protobuf->sprites_size();
  if (es->spriteCount > 0) {
    es->sprites = new Sprite[es->spriteCount];
    for (int i = 0; i < es->spriteCount; ++i) {
        es->sprites[i] = AddSprite(protobuf->sprites(i));
    }
  }

  es->soundCount = protobuf->sounds_size();
  if (es->soundCount > 0) {
    es->sounds = new Sound[es->soundCount];
    for (int i = 0; i < es->soundCount; ++i) {
        es->sounds[i] = AddSound(protobuf->sounds(i));
    }
  }

  es->backgroundCount = protobuf->backgrounds_size();
  if (es->backgroundCount > 0) {
    es->backgrounds = new Background[es->backgroundCount];
    for (int i = 0; i < es->backgroundCount; ++i) {
        es->backgrounds[i] = AddBackground(protobuf->backgrounds(i));
    }
  }

  es->pathCount = protobuf->paths_size();
  if (es->pathCount > 0) {
    es->paths = new Path[es->pathCount];
    for (int i = 0; i < es->pathCount; ++i) {
        es->paths[i] = AddPath(protobuf->paths(i));
    }
  }

  es->scriptCount = protobuf->scripts_size();
  if (es->scriptCount > 0) {
    es->scripts = new Script[es->scriptCount];
    for (int i = 0; i < es->scriptCount; ++i) {
        es->scripts[i] = AddScript(protobuf->scripts(i));
    }
  }

  es->shaderCount = protobuf->shaders_size();
  if (es->shaderCount > 0) {
    es->shaders = new Shader[es->shaderCount];
    for (int i = 0; i < es->shaderCount; ++i) {
        es->shaders[i] = AddShader(protobuf->shaders(i));
    }
  }

  es->fontCount = protobuf->fonts_size();
  if (es->fontCount > 0) {
    es->fonts = new Font[es->fontCount];
    for (int i = 0; i < es->fontCount; ++i) {
        es->fonts[i] = AddFont(protobuf->fonts(i));
    }
  }

  es->timelineCount = protobuf->timelines_size();
  if (es->timelineCount > 0) {
    es->timelines = new Timeline[es->timelineCount];
    for (int i = 0; i < es->timelineCount; ++i) {
        es->timelines[i] = AddTimeline(protobuf->mutable_timelines(i), protobuf);
    }
  }

  es->gmObjectCount = protobuf->objects_size();
  if (es->gmObjectCount > 0) {
    es->gmObjects = new GmObject[es->gmObjectCount];
    for (int i = 0; i < es->gmObjectCount; ++i) {
        es->gmObjects[i] = AddObject(protobuf->mutable_objects(i), protobuf);
    }
  }

  es->roomCount = protobuf->rooms_size();
  if (es->roomCount > 0) {
    es->rooms = new Room[es->roomCount];
    for (int i = 0; i < es->roomCount; ++i) {
        es->rooms[i] = AddRoom(protobuf->rooms(i), protobuf);
    }
  }

  return es;
}

Sprite AddSprite(const buffers::resources::Sprite& spr) {
  Sprite s = Sprite();

  s.name = spr.name().c_str();
  s.id = spr.id();

  s.transparent = spr.transparent();
  s.shape = spr.shape();
  s.alphaTolerance = spr.alpha_tolerance();
  s.separateMask = spr.separate_mask();
  s.smoothEdges = spr.smooth_edges();
  s.preload = spr.preload();
  s.originX = spr.origin_x();
  s.originY = spr.origin_y();

  s.bbMode = spr.bbox_mode();
  s.bbLeft = spr.bbox_left();
  s.bbRight = spr.bbox_right();
  s.bbTop = spr.bbox_top();
  s.bbBottom = spr.bbox_bottom();

  s.subImageCount = spr.subimages_size();
  if (s.subImageCount > 0) {
    s.subImages = new SubImage[s.subImageCount];
    for (int i = 0; i < s.subImageCount; ++i) {
      s.subImages[i].image = AddImage(spr.subimages(i));
    }
  }

  // Polygon_LOLWINDOWS *maskShapes; ???

  return s;
}

Sound AddSound(const buffers::resources::Sound& snd) {
  Sound s = Sound();

  s.name = snd.name().c_str();
  s.id = snd.id();

  s.kind = snd.kind();
  s.fileType = snd.file_extension().c_str();
  s.fileName = snd.file_name().c_str();
  s.volume = snd.volume();
  s.pan = snd.pan();
  s.preload = snd.preload();

  std::cout << snd.data() << " HEYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n";

  // Open sound
  FILE *afile = fopen(snd.data().c_str(),"rb");
  if (!afile)
    return s;

  // Buffer sound
  fseek(afile,0,SEEK_END);
  const size_t flen = ftell(afile);
  unsigned char *fdata = new unsigned char[flen];
  fseek(afile,0,SEEK_SET);
  if (fread(fdata,1,flen,afile) != flen)
    puts("WARNING: Resource stream cut short while loading sound data");

  s.data = fdata;
  s.size = flen;

  return s;
}

Background AddBackground(const buffers::resources::Background& bkg) {
  Background b = Background();

  b.name = bkg.name().c_str();
  b.id = bkg.id();

  b.transparent = bkg.transparent();
  b.smoothEdges = bkg.smooth_edges();
  b.preload = bkg.preload();
  b.useAsTileset = bkg.use_as_tileset();

  b.tileWidth = bkg.tile_width();
  b.tileHeight = bkg.tile_height();
  b.hOffset = bkg.horizontal_offset();
  b.vOffset = bkg.vertical_offset();
  b.hSep = bkg.horizontal_spacing();
  b.vSep = bkg.vertical_spacing();

  b.backgroundImage = AddImage(bkg.image());

  return b;
}

Path AddPath(const buffers::resources::Path& pth) {
  Path p = Path();

  p.name = pth.name().c_str();
  p.id = pth.id();

  p.smooth = pth.smooth();
  p.closed = pth.closed();
  p.precision = pth.precision();

  p.snapX = pth.snap_x();
  p.snapY = pth.snap_y();

  p.pointCount = pth.points_size();
  if (p.pointCount > 0) {
    p.points = new PathPoint[p.pointCount];
    for (int i=0; i < p.pointCount; ++i) {
      p.points[i] = AddPathPoint(pth.points(i));
    }
  }

  return p;
}

PathPoint AddPathPoint(const buffers::resources::Path::Point& pnt) {
  PathPoint p = PathPoint();

  p.x = pnt.x();
  p.y = pnt.y();
  p.speed = pnt.speed();

  return p;
}

Script AddScript(const buffers::resources::Script& scr) {
  Script s = Script();

  s.name = scr.name().c_str();
  s.id = scr.id();

  s.code = scr.code().c_str();

  return s;
}

Shader AddShader(const buffers::resources::Shader& shr) {
  Shader s = Shader();

  s.name = shr.name().c_str();
  s.id = shr.id();

  s.vertex = shr.vertex_code().c_str();
  s.fragment = shr.fragment_code().c_str();
  s.type = shr.type().c_str();
  s.precompile = shr.precompile();

  return s;
}

Font AddFont(const buffers::resources::Font& fnt) {
  Font f = Font();

  f.name = fnt.name().c_str();
  f.id = fnt.id();

  f.fontName = fnt.font_name().c_str();
  f.size = fnt.size();
  f.bold = fnt.bold();
  f.italic = fnt.italic();

  return f;
}

Timeline AddTimeline(buffers::resources::Timeline* tml, buffers::Project* protobuf) {
  Timeline t = Timeline();

  t.name = tml->name().c_str();
  t.id = tml->id();

  t.momentCount = tml->moments_size();
  if (t.momentCount > 0) {
    t.moments = new Moment[t.momentCount];
    for (int i = 0; i < t.momentCount; ++i) {
        //t.moments[i] = AddMoment(tml->mutable_moments(i), protobuf);
    }
  }

  return t;
}

GmObject AddObject(buffers::resources::Object* obj, buffers::Project* protobuf) {
  GmObject o = GmObject();

  o.name = obj->name().c_str();
  o.id = obj->id();

  o.spriteId = Name2Id(protobuf->sprites(), obj->sprite_name());
  o.solid = obj->solid();
  o.visible = obj->visible();
  o.depth = obj->depth();
  o.persistent = obj->persistent();
  o.parentId = Name2Id(protobuf->objects(), obj->parent_name());
  o.maskId = Name2Id(protobuf->sprites(), obj->mask_name());

  std::unordered_map<int,std::vector<Event> > mainEventMap;

  for (int i = 0; i < obj->events_size(); ++i) {
    auto *evt = obj->mutable_events(i);
    std::vector<Event>& events = mainEventMap[evt->type()];
    Event e;
    e.id = evt->number();
    if (evt->actions_size() > 0)
      evt->set_code(Actions2Code(evt->actions()));
    e.code = evt->code().c_str();
    events.push_back(e);
  }

  o.mainEventCount = mainEventMap.size();
  if (o.mainEventCount > 0) {
    o.mainEvents = new MainEvent[o.mainEventCount];
    int m = 0;
    for (const auto &mainEvent : mainEventMap) {
      MainEvent me = MainEvent();
      me.id = mainEvent.first;
      me.eventCount = mainEvent.second.size();
      if (me.eventCount > 0) {
        me.events = new Event[me.eventCount];
        for (int i = 0; i < me.eventCount; ++i) {
          me.events[i] = mainEvent.second[i];
        }
      }
      o.mainEvents[m++] = me;
    }
  }

  return o;
}

Room AddRoom(const buffers::resources::Room& rmn, buffers::Project* protobuf) {
  Room r = Room();

  r.name = rmn.name().c_str();
  r.id = rmn.id();

  r.caption = rmn.caption().c_str();
  r.width = rmn.width();
  r.height = rmn.height();
  r.speed = rmn.speed();
  r.persistent = rmn.persistent();
  r.backgroundColor = 0x40C0FFFF;
  r.drawBackgroundColor = rmn.show_color();
  r.creationCode = rmn.code().c_str();
  r.enableViews = rmn.enable_views();

  r.backgroundDefCount = rmn.backgrounds_size();
  if (r.backgroundDefCount > 0) {
    r.backgroundDefs = new BackgroundDef[r.backgroundDefCount];
    for (int i = 0; i < r.backgroundDefCount; ++i) {
      r.backgroundDefs[i] = AddRoomBackground(rmn.backgrounds(i), protobuf);
    }
  }

  r.viewCount = rmn.views_size();
  if (r.viewCount > 0) {
    r.views = new View[r.viewCount];
    for (int i = 0; i < r.viewCount; ++i) {
      r.views[i] = AddView(rmn.views(i), protobuf);
    }
  }

  r.instanceCount = rmn.instances_size();
  if (r.instanceCount > 0) {
    r.instances = new Instance[r.instanceCount];
    for (int i = 0; i < r.instanceCount; ++i) {
      r.instances[i] = AddInstance(rmn.instances(i), protobuf);
    }
  }

  r.tileCount = rmn.tiles_size();
  if (r.tileCount > 0) {
    r.tiles = new Tile[r.tileCount];
    for (int i = 0; i < r.tileCount; ++i) {
      r.tiles[i] = AddTile(rmn.tiles(i), protobuf);
    }
  }

  return r;
}

Instance AddInstance(const buffers::resources::Room::Instance& inst, buffers::Project* protobuf) {
  Instance i = Instance();

  i.id = inst.id();
  i.objectId = Name2Id(protobuf->objects(), inst.object_type());
  i.x = inst.x();
  i.y = inst.y();
  i.locked = inst.locked();
  i.creationCode = inst.code().c_str();
  i.preCreationCode = "";

  return i;
}

Tile AddTile(const buffers::resources::Room::Tile& tile, buffers::Project* protobuf) {
  Tile t = Tile();

  t.id = tile.id();
  t.backgroundId = Name2Id(protobuf->backgrounds(), tile.background_name());
  t.roomX = tile.x();
  t.roomY = tile.y();
  t.locked = tile.locked();
  t.bgX = tile.xoffset();
  t.bgY = tile.yoffset();
  t.width = tile.width();
  t.height = tile.height();
  t.depth = tile.depth();

  return t;
}

View AddView(const buffers::resources::Room::View& view, buffers::Project* protobuf) {
  View v = View();

  v.visible = view.visible();
  v.viewX = view.xview();
  v.viewY = view.yview();
  v.viewW = view.wview();
  v.viewH = view.hview();
  v.portX = view.xport();
  v.portY = view.yport();
  v.portW = view.wport();
  v.portH = view.hport();
  v.borderH = view.hborder();
  v.borderV = view.vborder();
  v.speedH = view.hspeed();
  v.speedV = view.vspeed();
  v.objectId = Name2Id(protobuf->objects(), view.object_following());

  return v;
}

BackgroundDef AddRoomBackground(const buffers::resources::Room::Background& bkg, buffers::Project* protobuf) {
  BackgroundDef b = BackgroundDef();

  b.visible = bkg.visible();
  b.foreground = bkg.foreground();
  b.x = bkg.x();
  b.y = bkg.y();
  b.tileHoriz = bkg.htiled();
  b.tileVert = bkg.vtiled();
  b.hSpeed = bkg.hspeed();
  b.vSpeed = bkg.vspeed();
  b.stretch = bkg.stretch();
  b.backgroundId = Name2Id(protobuf->backgrounds(), bkg.name());

  return b;
}
