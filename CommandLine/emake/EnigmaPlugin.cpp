#include "EnigmaPlugin.hpp"
#include "Main.hpp"
#include "Proto2ES.h"

#include "OS_Switchboard.h"

#if CURRENT_PLATFORM_ID == OS_WINDOWS
#	include <windows.h>
#	include <process.h>
#else
#	include <pthread.h>
#	include <unistd.h>
#	include <dlfcn.h>
#endif

#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

EnigmaPlugin::EnigmaPlugin()
{
}

int EnigmaPlugin::Load()
{
  // Load Plugin
#if CURRENT_PLATFORM_ID == OS_WINDOWS
#	define dlopen(x, y) LoadLibrary(x)
#define dlerror() "Can't be arsed to implement windows errors" //FIXME
  std::string extension = ".dll";
  std::string prefix = "";
#elif CURRENT_PLATFORM_ID ==  OS_MACOSX
  std::string extension = ".dylib";
  std::string prefix = "lib";
#else
  std::string extension = ".so";
  std::string prefix = "lib";
#endif

  std::string pluginName = "./" + prefix + "compileEGMf" + extension;

  _handle = dlopen(pluginName.c_str(), RTLD_LAZY);

  if (!_handle)
  {
    errorStream  << "Error Loading Plugin '" << pluginName << "'" << std::endl;
    errorStream << dlerror() << std::endl;
    return PLUGIN_ERROR;
  }

  // Bind Functions
#if CURRENT_PLATFORM_ID == OS_WINDOWS
#	define BindFunc(x, y) GetProcAddress(static_cast<HMODULE>(x), y)
#else
#	define BindFunc(x, y) dlsym(x, y)
#endif

  plugin_Init = reinterpret_cast<const char*(*)(EnigmaCallbacks*)>(BindFunc(_handle, "libInit"));
  plugin_CompileEGM = reinterpret_cast<int (*)(EnigmaStruct *es, const char* exe_filename, int mode)>(BindFunc(_handle, "compileEGMf"));
  plugin_NextResource = reinterpret_cast<const char* (*)()>(BindFunc(_handle, "next_available_resource"));
  plugin_FirstResource = reinterpret_cast<const char* (*)()>(BindFunc(_handle, "first_available_resource"));
  plugin_ResourceIsFunction = reinterpret_cast<bool (*)()>(BindFunc(_handle, "resource_isFunction"));
  plugin_ResourceArgCountMin = reinterpret_cast<int (*)()>(BindFunc(_handle, "resource_argCountMin"));
  plugin_ResourceArgCountMax = reinterpret_cast<int (*)()>(BindFunc(_handle, "resource_argCountMax"));
  plugin_ResourceOverloadCount = reinterpret_cast<int (*)()>(BindFunc(_handle, "resource_overloadCount"));
  plugin_ResourceParameters = reinterpret_cast<const char* (*)(int i)>(BindFunc(_handle, "resource_paramters"));
  plugin_ResourceIsTypeName = reinterpret_cast<int (*)()>(BindFunc(_handle, "resource_isTypeName"));
  plugin_ResourceIsGlobal = reinterpret_cast<int (*)()>(BindFunc(_handle, "resource_isGlobal"));
  plugin_ResourcesAtEnd = reinterpret_cast<bool (*)()>(BindFunc(_handle, "resources_atEnd"));
  plugin_Free = reinterpret_cast<void (*)()>(BindFunc(_handle, "libFree"));
  plugin_DefinitionsModified = reinterpret_cast<syntax_error* (*)(const char*, const char*)>(BindFunc(_handle, "definitionsModified"));
  plugin_SyntaxCheck = reinterpret_cast<syntax_error* (*)(int, const char**, const char*)>(BindFunc(_handle, "syntaxCheck"));
  plugin_HandleGameLaunch = reinterpret_cast<void (*)()>(BindFunc(_handle, "ide_handles_game_launch"));
  plugin_LogMakeToConsole = reinterpret_cast<void (*)()>(BindFunc(_handle, "log_make_to_console"));

  return PLUGIN_SUCCESS;
}

const char* EnigmaPlugin::Init()
{
  CallBack ecb;
  return plugin_Init(&ecb);
}

syntax_error* EnigmaPlugin::SetDefinitions(const char* def, const char* yaml)
{
  return plugin_DefinitionsModified(def, yaml);
}

syntax_error* EnigmaPlugin::SetDefinitions(const char* yaml)
{
  return plugin_DefinitionsModified("", yaml);
}

syntax_error* EnigmaPlugin::SyntaxCheck(int count, const char** names, const char* code)
{
  return plugin_SyntaxCheck(count, names, code);
}

void EnigmaPlugin::HandleGameLaunch()
{
  plugin_HandleGameLaunch();
}

void EnigmaPlugin::LogMakeToConsole()
{
  plugin_LogMakeToConsole();
}

int EnigmaPlugin::BuildGame(EnigmaStruct* data, GameMode mode, const char* fpath)
{
  return plugin_CompileEGM(data, fpath, mode);
}

int EnigmaPlugin::BuildGame(buffers::Game* data, GameMode mode, const char* fpath)
{
  EnigmaStruct *es = Proto2ES(data);
  es->filename = fpath;
  return plugin_CompileEGM(es, fpath, mode);
}

const char* EnigmaPlugin::NextResource() {
  return plugin_NextResource();
}

const char* EnigmaPlugin::FirstResource() {
  return plugin_FirstResource();
}

bool EnigmaPlugin::ResourceIsFunction() {
  return plugin_ResourceIsFunction();
}

int EnigmaPlugin::ResourceArgCountMin() {
  return plugin_ResourceArgCountMin();
}

int EnigmaPlugin::ResourceArgCountMax() {
  return plugin_ResourceArgCountMax();
}

int EnigmaPlugin::ResourceOverloadCount() {
  return plugin_ResourceOverloadCount();
}

const char* EnigmaPlugin::ResourceParameters(int i) {
  return plugin_ResourceParameters(i);
}

int EnigmaPlugin::ResourceIsTypeName() {
  return plugin_ResourceIsTypeName();
}

int EnigmaPlugin::ResourceIsGlobal() {
  return plugin_ResourceIsGlobal();
}

bool EnigmaPlugin::ResourcesAtEnd() {
  return plugin_ResourcesAtEnd();
}
