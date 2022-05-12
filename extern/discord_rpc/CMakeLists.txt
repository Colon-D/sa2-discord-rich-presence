cmake_minimum_required(VERSION 3.14)
include(FetchContent)

FetchContent_Declare(
  "discord_rpc"
  GIT_REPOSITORY "https://github.com/discord/discord-rpc"
  GIT_TAG        "963aa9f3e5ce81a4682c6ca3d136cddda614db33"
)
set(BUILD_EXAMPLES OFF)
FetchContent_MakeAvailable("discord_rpc")

target_include_directories("discord-rpc" PUBLIC
    "${discord_rpc_SOURCE_DIR}/include"
)
