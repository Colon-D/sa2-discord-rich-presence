# Discord Rich Presence

This mod adds Discord Rich Presence to the game, similar to [DiscordSADX](https://gamebanana.com/tools/6405) except not similar at all because this is made by me and not SuperSonic16.

The Rich Presence will look different depending on what you are doing in the game, but in general:
- The Action Stage will be shown through the Large Image.
- The Character will be shown through the Small Image.
- The Rings and Lives will be shown through the Details.
- The Timer will be shown through the Timestamps.
- Being paused will be shown through the State, alongside the Boss if applicable.

Example:

<img src="resources/README/example.png" alt="Example Image of Discord Rich Presence" width="32%">

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

# License

It's complicated 🙃. I hate licenses.

My code is under [CC0](https://creativecommons.org/share-your-work/public-domain/cc0/), apart from under comments stating I have stolen something.

Note that most mods are using GameBanana's default license of [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/). Anything that does not have a license, I am stealing. When attributing a mod I am using the Submitter.

Libraries:
- [Discord RPC](https://github.com/discord/discord-rpc) by [Discord](https://discord.com/) - [MIT license](https://github.com/discord/discord-rpc/blob/master/LICENSE).
- [sa2-mod-loader](https://github.com/X-Hax/sa2-mod-loader) by [X-Hax](https://github.com/X-Hax)
- [mod-loader-common](https://github.com/sonicretro/mod-loader-common) by [SonicRetro](https://sonicretro.org/)

Discord Art Assets:
- Small Image Assets:
  - Characters:
    - All characters owned by [SEGA](https://www.sega.com/)
    - [Super Shadow](https://www.deviantart.com/mrmephilesthedark/art/Super-Shadow-682421551) fanart by [MrMephilestheDark](https://www.deviantart.com/mrmephilesthedark) edited by me to glow
    - All other character art is owned by [SEGA](https://www.sega.com/)?
  - Miscellaneous
    - Upscaled image assets from [SA2 ESRGAN HD Textures](https://gamebanana.com/mods/48913) by [Edinidium119](https://gamebanana.com/members/1753455) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
- Large Image Assets:
  - Screenshots use these mods:
    - [No Model Tinting](https://gamebanana.com/mods/48874) by [SPEEPSHighway](https://gamebanana.com/members/1667635) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - [Restored GUN Logos](https://gamebanana.com/mods/48914) by [SPEEPSHighway](https://gamebanana.com/members/1667635) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - [SA2 ESRGAN HD Textures](https://gamebanana.com/mods/48913) by [Edinidium119](https://gamebanana.com/members/1753455) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - [Higher Draw Distance](https://gamebanana.com/mods/48947) by [Kell](https://gamebanana.com/members/1645179) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - [Presentable Eggman Stages](https://gamebanana.com/mods/48956) by [SPEEPSHighway](https://gamebanana.com/members/1667635) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - [Kart Stage Water Fix](https://gamebanana.com/mods/325723) by [Ellasent](https://gamebanana.com/members/1660031) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - [Cutscene Revamp](https://gamebanana.com/mods/48872) by [SPEEPSHighway](https://gamebanana.com/members/1667635) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - [Dreamcast Characters](https://gamebanana.com/wips/48797) by [End User](https://gamebanana.com/members/1647561)
    - [HD GUI: SA2 Edition](https://gamebanana.com/mods/33171) by [SPEEPSHighway](https://gamebanana.com/members/1667635) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
    - "Custom Stages/Ports":
      - [Emerald Coast](https://gamebanana.com/mods/148604) by [MainMemory](https://gamebanana.com/members/1599368)
      - [Nintendo Gamecube (Mario Kart Double Dash)](https://gamebanana.com/mods/148617) by [GBA64](https://gamebanana.com/members/1531491) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Artisans (Spyro The Dragon)](https://gamebanana.com/mods/148598) by [GBA64](https://gamebanana.com/members/1531491) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Apotos Stage Entrance HUB](https://gamebanana.com/mods/148595) by [-[DEXTERITY]-](https://gamebanana.com/members/1654412) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Soleanna Garden (NEUTRAL) v2](https://gamebanana.com/mods/148622) by [-[DEXTERITY]-](https://gamebanana.com/members/1654412) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Windmill Isle Act 1 Unwiished](https://gamebanana.com/mods/148628) by [-[DEXTERITY]-](https://gamebanana.com/members/1654412) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Speed Highway](https://gamebanana.com/mods/304650) by [Sora_yx](https://gamebanana.com/members/1693553) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Pyre Roads DOUBLE PACK](https://gamebanana.com/mods/307565) by [HoppyBoppyBunny](https://gamebanana.com/members/1707790) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [SA2 Heroes Mod](https://gamebanana.com/mods/48934) by [Kell](https://gamebanana.com/members/1645179) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Glyphic Canyon](https://gamebanana.com/mods/348096) by [ShawnGuku](https://gamebanana.com/members/1688024) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Lethal Highway](https://gamebanana.com/mods/361081) by [HoppyBoppyBunny](https://gamebanana.com/members/1707790) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [SA2 Past Garden](https://gamebanana.com/mods/358991) by [Sora_yx](https://gamebanana.com/members/1693553) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
      - [Chao World Extended](https://gamebanana.com/mods/48840)'s SADX Gardens by [Shaddatic](https://gamebanana.com/members/1719452) - [CC BY-NC-ND 4.0](http://creativecommons.org/licenses/by-nc-nd/4.0/)
  - The "unknown" image asset is from [HD GUI for Character Select Plus](https://gamebanana.com/mods/33162) by [CheatFreak](https://gamebanana.com/members/1614644) - [CC BY-NC 4.0](https://creativecommons.org/licenses/by-nc/4.0/)
  - The "menu" image asset is from [HD GUI: SA2 Edition](https://gamebanana.com/mods/33171) by [SPEEPSHighway](https://gamebanana.com/members/1667635) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)

Other (referenced and not already attributed):
- [DiscordSADX](https://gamebanana.com/tools/6405) by [SuperSonic16](https://gamebanana.com/members/1605939) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
- [Chao World Extended](https://gamebanana.com/mods/48840) by [DarkyBenji](https://gamebanana.com/members/1515314) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
- [Chao Karate: Buster's Tournament](https://gamebanana.com/mods/48869) by [CGBuster](https://gamebanana.com/members/1633884) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
- [SA2 Super Sonic / Shadow](https://gamebanana.com/mods/340288) by [Sora_yx](https://gamebanana.com/members/1693553) - [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)

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
