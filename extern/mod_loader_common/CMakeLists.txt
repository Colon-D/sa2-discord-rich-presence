cmake_minimum_required(VERSION 3.14)
include(FetchContent)

FetchContent_Declare(
  "mod_loader_common"
  GIT_REPOSITORY "https://github.com/sonicretro/mod-loader-common.git"
  GIT_TAG        "11106d63a986010f2a58942b0e8d18e914223381"
)
FetchContent_MakeAvailable("mod_loader_common")

add_library("mod_loader_common" STATIC
    "${mod_loader_common_SOURCE_DIR}/ModLoaderCommon/CodeParser.cpp"
    "${mod_loader_common_SOURCE_DIR}/ModLoaderCommon/FileSystem.cpp"
    "${mod_loader_common_SOURCE_DIR}/ModLoaderCommon/IniFile.cpp"
    "${mod_loader_common_SOURCE_DIR}/ModLoaderCommon/stdafx.cpp"
    "${mod_loader_common_SOURCE_DIR}/ModLoaderCommon/TextConv.cpp"
)
target_include_directories("mod_loader_common" PUBLIC
    "${mod_loader_common_SOURCE_DIR}/ModLoaderCommon"
)
