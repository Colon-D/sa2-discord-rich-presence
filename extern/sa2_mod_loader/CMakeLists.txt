cmake_minimum_required(VERSION 3.14)
include(FetchContent)

FetchContent_Declare(
  "sa2_mod_loader"
  GIT_REPOSITORY "https://github.com/X-Hax/sa2-mod-loader.git"
  GIT_TAG        "7056ee5f7c36c31f77b2e855c81164b3c2f211a4"
)
FetchContent_MakeAvailable("sa2_mod_loader")

add_library("libmodutils" STATIC
    "${sa2_mod_loader_SOURCE_DIR}/libmodutils/stdafx.cpp"
    "${sa2_mod_loader_SOURCE_DIR}/libmodutils/LandTableInfo.cpp"
    "${sa2_mod_loader_SOURCE_DIR}/libmodutils/ModelInfo.cpp"
    "${sa2_mod_loader_SOURCE_DIR}/libmodutils/AnimationFile.cpp"
    "${sa2_mod_loader_SOURCE_DIR}/libmodutils/Trampoline.cpp"
    "${sa2_mod_loader_SOURCE_DIR}/libmodutils/GameObject.cpp"
)
target_include_directories("libmodutils" PUBLIC
    "${sa2_mod_loader_SOURCE_DIR}/SA2ModLoader/include"
    "${sa2_mod_loader_SOURCE_DIR}/libmodutils"
)
