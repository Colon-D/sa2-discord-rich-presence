# Discord Rich Presence

This mod adds Discord Rich Presence to the game, similar to [DiscordSADX](https://gamebanana.com/tools/6405) except not similar at all because this is made by me and not [SuperSonic16](https://gamebanana.com/members/1605939).

The Rich Presence will look different depending on what you are doing in the game, but in general:
- The Action Stage will be shown through the Large Image.
- The Character will be shown through the Small Image.
- The Rings and Lives will be shown through the Details.
- The Timer will be shown through the Timestamps.
- Being paused will be shown through the State, alongside the Boss if applicable.

Examples:

<img src="resources/README/example.png" alt="Example Image of Discord Rich Presence" width="32%"> <img src="resources/README/example_2.png" alt="Another Example Image of Discord Rich Presence" width="32%">

Other scenarios like being in the Menus, watching Events, Multiplayer, doing Chao stuff will display differently. The code is very messy, as I kept adding unneeded features and then removing them, so I can not exactly remember what is programmed to display on the Rich Presense and when.

Some features are omitted to try not clutter the Rich Presence (like score). Others are omitted due to burnout. Some are omitted because I am dumb and stupid, perhaps even a little bit stinky, yuck (like Time Remaining for Route 101 and Route 280). Ring and Life counter would have been omitted if they were not in DiscordSADX.

Most of the RPC will be bad, I am not good at designing things.

The "Author"s section in the mod's properties will only contain me.
It will not contain the name of those involved with the mods/resources I used
to create this mod.
This is because I do not wish to imply that they endorse me.
Perhaps this is the wrong thing to do. I am not good at handling things
involving others, and this mod uses other's resources a lot.
It worries me a lot, so I am very sorry if I have messed up.
On the [GameBanana page](https://gamebanana.com/mods/377099), and in the [license](LICENSE.md) I have listed every resource used, or referenced
anywhere. The Submitter of those resources is also mentioned, alongside the
author of subresources that I directly mention using.

# Compatibility

Coded to support:
- [Chao World Extended](https://gamebanana.com/mods/48840)'s new name limit
  - Newer Challenge Race's chao race names
  - SADX Gardens
- "[Chao Karate: Buster's Tournament](https://gamebanana.com/mods/48869)"'s Chao Karate Level names
- [Dreamcast Characters](https://gamebanana.com/wips/48797)' Big the Cat
- [SA2 Super Sonic / Shadow](https://gamebanana.com/mods/340288)
- Every mod currently under "Custom Stages/Ports":
  - [Emerald Coast](https://gamebanana.com/mods/148604)
  - [Nintendo Gamecube (Mario Kart Double Dash)](https://gamebanana.com/mods/148617)
  - [Artisans (Spyro The Dragon)](https://gamebanana.com/mods/148598)
  - [Apotos Stage Entrance HUB](https://gamebanana.com/mods/148595)
  - [Soleanna Garden (NEUTRAL) v2](https://gamebanana.com/mods/148622)
  - [Windmill Isle Act 1 Unwiished](https://gamebanana.com/mods/148628)
  - [Speed Highway](https://gamebanana.com/mods/304650)
  - [Pyre Roads DOUBLE PACK](https://gamebanana.com/mods/307565)
  - [SA2 Heroes Mod](https://gamebanana.com/mods/48934)
  - [Glyphic Canyon](https://gamebanana.com/mods/348096)
  - [Lethal Highway](https://gamebanana.com/mods/361081)
  - [SA2 Past Garden](https://gamebanana.com/mods/358991)

# Compile

## Command line

Have an up to date MSVC compiler installed alongside CMake installed. Neither Clang nor GCC compile for me. I have not tested any other C++ compilers.

- Make a folder to build in.\
Example: `mkdir build`
- Generate a Visual Studio Buildsystem with the Win32 architecture.\
Example: `cmake -S . -B build -G "Visual Studio 17 2022" -A Win32`
  - Optionally set the `SONIC_ADVENTURE_2_DIRECTORY` variable to your Sonic Adventure 2 directory. This does NOT have a default.\
This will build the dll into `${SONIC_ADVENTURE_2_DIRECTORY}/mods/sa2-discord-rich-presence`.\
"resources/SA2ModManager_mod"'s "configschema.xml" and "mod.ini" will also be copied into there.\
Example: `-D SONIC_ADVENTURE_2_DIRECTORY="C:\Directory to\Sonic Adventure 2"`.
- Build the mod.\
Example `cmake --build build --config Release`

## IDE

Use your IDE's CMake support.

I used Visual Studio Code to make this mod.

- Install the "CMake Tools" extension.
- Open this repository's folder in Visual Studio Code.
- Change the active kit to an up to date MSVC 32-bit compiler. Neither Clang nor GCC compile for me. I have not tested any other C++ compilers.
  Example: `Ctrl+Shift+P` -> `>CMake: Select a Kit` -> `Visual Studio Community 2022 Release - amd64_x86`
- Optionally set the `SONIC_ADVENTURE_2_DIRECTORY` variable to your Sonic Adventure 2 directory. This does NOT have a default.\
This will build the dll into `${SONIC_ADVENTURE_2_DIRECTORY}/mods/sa2-discord-rich-presence`.\
"resources/SA2ModManager_mod"'s "configschema.xml" and "mod.ini" will also be copied into there.\
Example: `Ctrl+Shift+P` -> `>CMake: Edit CMake Cache` -> Set `SONIC_ADVENTURE_2_DIRECTORY:PATH` to `C:/Directory to/Sonic Adventure 2` -> Save with `Ctrl+S`
- Optionally set the build variant.\
Example: `Ctrl+Shift+P` -> `>CMake: Select Variant` -> `Release`
- Build the mod.\
Example: `Ctrl+Shift+P` -> `>CMake: Build`
