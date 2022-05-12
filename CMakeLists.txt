cmake_minimum_required(VERSION 3.20)

project("sa2_discord_rich_presence")

add_library("${PROJECT_NAME}" SHARED
    "src/main.cpp"
    "src/level.cpp"
    "src/asset_name.cpp"
    "src/character.cpp"
    "src/discord_rich_presence.cpp"
    "src/free_cam.cpp"
    "src/player.cpp"
    "src/chao.cpp"
    "src/modding.cpp"
    "src/menu.cpp"
    "src/clipboard.cpp"
    "src/ini_settings.cpp"
    "src/events.cpp"
    "src/level_timer.cpp"
)
target_include_directories("${PROJECT_NAME}" PUBLIC "include")
# cxx_std_23 needed instead of cxx_std_20 for std::format (used for timer),
# despite std::format being in c++20...
target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_23)

add_subdirectory(extern)
target_link_libraries("${PROJECT_NAME}" PUBLIC
    "mod_loader_common"
    "libmodutils"
    "discord-rpc"
)

# get Sonic Adventure 2 directory
set("SONIC_ADVENTURE_2_DIRECTORY" "" CACHE PATH "")
# convert to forward slashes
cmake_path(SET "SONIC_ADVENTURE_2_DIRECTORY" "${SONIC_ADVENTURE_2_DIRECTORY}")
# if directory exists
IF(EXISTS "${SONIC_ADVENTURE_2_DIRECTORY}")
    # set mod directory
    set(
        "MOD_DIRECTORY"
        "${SONIC_ADVENTURE_2_DIRECTORY}/mods/sa2-discord-rich-presence"
    )
    # set runtime output directory to mod directory
    set_target_properties("${PROJECT_NAME}" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${MOD_DIRECTORY}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${MOD_DIRECTORY}"
    )
    # copy files from "resources/SA2ModManager_mod" to mod directory
    configure_file(
        "${CMAKE_SOURCE_DIR}/resources/SA2ModManager_mod/mod.ini"
        "${MOD_DIRECTORY}/mod.ini"
        COPYONLY
    )
    configure_file(
        "${CMAKE_SOURCE_DIR}/resources/SA2ModManager_mod/configschema.xml"
        "${MOD_DIRECTORY}/configschema.xml"
        COPYONLY
    )
ELSE()
    message(WARNING "SONIC_ADVENTURE_2_DIRECTORY not found")
ENDIF()
