/** Copyright (C) 2018 Greg Williamson, Robert B. Colton
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

#include "codegen/project.pb.h"

#include <string>

namespace gmx {
buffers::Project* LoadGMX(std::string fName, bool verbose = false);
buffers::resources::Background* LoadBackground(std::string fName, bool verbose);
buffers::resources::Sound* LoadSound(std::string fName, bool verbose);
buffers::resources::Sprite* LoadSprite(std::string fName, bool verbose);
buffers::resources::Shader* LoadShader(std::string fName, bool verbose);
buffers::resources::Font* LoadFont(std::string fName, bool verbose);
buffers::resources::Object* LoadObject(std::string fName, bool verbose);
buffers::resources::Timeline* LoadTimeLine(std::string fName, bool verbose);
buffers::resources::Room* LoadRoom(std::string fName, bool verbose);
buffers::resources::Path* LoadPath(std::string fName, bool verbose);
buffers::resources::Script* LoadScript(std::string fName, bool verbose);
}  //namespace gmx
