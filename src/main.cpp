#include "sa2_discord_rich_presence/clipboard.h"
#include "sa2_discord_rich_presence/discord_rich_presence.h"
#include "sa2_discord_rich_presence/events.h"
#include "sa2_discord_rich_presence/free_cam.h"
#include "sa2_discord_rich_presence/ini_settings.h"
#include "sa2_discord_rich_presence/level.h"
#include "sa2_discord_rich_presence/menu.h"
#include "sa2_discord_rich_presence/modding.h"
#include <SA2ModLoader.h>
#include <array>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <unordered_set>

std::unique_ptr<discord> discord{};

extern "C" {
__declspec(dllexport) void Init(
	const char* const path, const HelperFunctions& /*helper_functions*/
) {
	// load settings from ini file
	ini::load(path);

	discord = std::make_unique<class discord>();
	discord->update_rich_presence([](discord::rich_presence& rpc) {
		rpc = {};
		rpc.details = "Starting Up...";
	});

	// set console to use utf8, (for logging chao name)
	// I am sure this won't break any other mods :)
	SetConsoleOutputCP(65001);

	init_freeze_time();

	read_mods_and_codes();

	// replace level names for "Custom Stages/Ports",
	// have to do this in order, else another mod might override the same level
	for (const auto& mod : mod_order) {
		if (mod == "Emerald Coast") {
			set_level_name(
				LevelIDs::LevelIDs_CityEscape, "Emerald Coast", true
			);
		}
		else if (mod == "Nintendo Gamecube") {
			set_level_name(
				LevelIDs::LevelIDs_HiddenBase2P, "Nintendo Gamecube", true
			);
		}
		else if (mod == "ArtisansHome") {
			set_level_name(LevelIDs::LevelIDs_WildCanyon, "Artisans", true);
			set_level_name(LevelIDs::LevelIDs_WildCanyon2P, "Artisans", true);
		}
		else if (mod == "Apotos Stage Entrance Hub") {
			set_level_name(
				LevelIDs::LevelIDs_MetalHarbor,
				"Apotos Stage Entrance Hub",
				true
			);
		}
		else if (mod == "Soleanna Garden (Neutral)") {
			set_chao_area_name(
				chao_area::chao_garden, "Soleanna Garden", true
			);
		}
		else if (mod == "Windmill Isle Act 1 Unwiished") {
			set_level_name(
				LevelIDs::LevelIDs_CityEscape,
				"Windmill Isle Act 1 Unwiished",
				true
			);
		}
		else if (mod == "Speed Highway") {
			set_level_name(
				LevelIDs::LevelIDs_RadicalHighway, "Speed Highway", true
			);
		}
		else if (mod == "Pyre roads double pack") {
			set_route_101_280_name(false, "Brimstone Blitz 661", true);
			set_route_101_280_name(true,  "Sinister Coil 666", true);
		}
		else if (mod == "Heroes Conversion") {
			set_level_name(
				LevelIDs::LevelIDs_CityEscape, "Seaside Hill", true
			);
			set_level_name(
				LevelIDs::LevelIDs_MetalHarbor, "Ocean Palace", true
			);
			set_level_name(
				LevelIDs::LevelIDs_MetalHarbor2P, "Ocean Palace", true
			);
		}
		else if (mod == "Glyphic Canyon") {
			set_level_name(LevelIDs::LevelIDs_SkyRail, "Glyphic Canyon", true);
		}
		else if (mod == "Lethal Highway") {
			set_level_name(
				LevelIDs::LevelIDs_RadicalHighway, "Lethal Highway", true
			);
		}
		else if (mod == "SA2 Past Garden") {
			set_chao_area_name(
				chao_area::chao_garden, "Emerald Altar Garden", true
			);
		}
		else if (mod == "SADX Gardens") {
			set_chao_area_name(
				chao_area::dark_garden, "Egg Carrier Garden", true
			);
			set_chao_area_name(
				chao_area::chao_garden, "Station Square Garden", true
			);
			set_chao_area_name(
				chao_area::dark_garden, "Mystic Ruins Garden", true
			);
		}
	}
}

__declspec(dllexport) void __cdecl OnFrame() {
	//update_chao_race_doors_on_frame();

	discord->update_rich_presence([](discord::rich_presence& rpc) {
		rpc = {};

		static gamemode gamemode_last_frame{};
		const auto current_gamemode{ static_cast<::gamemode>(GameMode) };
		switch (current_gamemode) {
		case gamemode::event: {
			// check gamemode last frame,
			// as it takes a frame for the event to be set.
			// like most things I do, there is probably a better way to do this
			if (gamemode_last_frame != gamemode::event) {
				break;
			}
			// check if event should be skipped
			if (event_should_be_skipped(current_event)) {
				rpc = {};
				break;
			}
			if (
				const auto event_asset_name =
					::event_asset_name(current_event)
			) {
				rpc.large_image_key = *event_asset_name;
			}
			else {
				// display unknown event
				rpc.large_image_key = "unknown";
			}
			rpc.large_image_text =
				"Event " + std::to_string(static_cast<int>(current_event));
			rpc.details = "Watching an Event";
			if (const auto event_name = ::event_name(current_event)) {
				rpc.state = *event_name;
			}
			else {
				// display unknown event
				rpc.state = "Unknown Event "
					+ std::to_string(static_cast<int>(current_event));
			}
			break;
		}
		case gamemode::demo:
			if (GameState == GameStates::GameStates_Ingame) {
				rpc.details = "Watching a Demo";
				update_level_small_image(rpc);
				update_level_large_image(rpc);
			}
			break;
		case gamemode::emblem_screen:
			rpc.details = "Earning an Emblem";
			rpc.state = std::to_string(+EmblemCount) + "/120";
			rpc.large_image_key = "emblem";
			rpc.large_image_text = "Emblem screen";
			break;
		case gamemode::menu: {
			static menu menu_last_frame{};
			const auto current_menu = static_cast<menu>(CurrentMenu);
			// menu sometimes is wrong for 1 frame
			if (menu_last_frame == current_menu) {
				rpc.details = "Navigating the Menu";
				rpc.state = menu_name(current_menu);
				if (current_menu == menu::emblem_results) {
					rpc.state += ": " + std::to_string(+EmblemCount) + "/120";
				}
				rpc.large_image_key = "menu";
				// violating DRY since I do not have seperate images for each
				// menu. This is the only place where text repeats, I think.
				// I do not think screenshots of the menu look nice as assets.
				rpc.large_image_text = menu_name(current_menu);
			}
			menu_last_frame = current_menu;
			break;
		}
		case gamemode::level: {
			update_level_rpc(rpc);
			break;
		}
		default:
			break;
		}
		gamemode_last_frame = current_gamemode;
	});

	update_free_cam_on_frame();
}

__declspec(dllexport) void __cdecl OnInput() {
	if (auto* const controller{ ControllerPointers[0] }) {
		// if debug_mode and L + R are held
		if (
			ini::debug_mode
			&& (controller->on & Buttons::Buttons_L) != 0
			&& (controller->on & Buttons::Buttons_R) != 0
		) {
			// toggle free cam on dpad up
			if ((controller->press & Buttons::Buttons_Up) != 0) {
				toggle_free_cam();
			}
			// toggle freeze time on dpad left
			else if ((controller->press & Buttons::Buttons_Left) != 0) {
				toggle_freeze_time();
			}
			// load a cutscene from index in clipboard on dpad right,
			// only works in level and once
			else if ((controller->press & Buttons::Buttons_Right) != 0) {
				if (static_cast<gamemode>(GameMode) == gamemode::level) {
					std::istringstream clipboard{ read_clipboard() };
					int16_t clipboard_event_id{};
					if (clipboard >> clipboard_event_id) {
						// stolen from
						// https://github.com/X-Hax/sa2-mod-loader/blob/1363b664fc5dd1e0cc5e1b640ebf02039b3a4b6f/SA2ModLoader/testspawn.cpp#L259
						auto& events = ref<StoryEntry>(0x173A5E0).Events;
						// use all events because I accidently let events
						// finish, thus needing to restart the game
						for (auto& event : events) {
							event = clipboard_event_id;
						}
						GameMode = static_cast<int>(gamemode::initialize);
					}
				}
				else {
					CurrentLevel = LevelIDs::LevelIDs_BasicTest;
					GameMode = static_cast<int>(gamemode::start_level);
				}
			}
		}

		if (is_free_cam_enabled()) {
			update_free_cam_on_input();

			// eat input
			controller->press = 0;
			controller->off = (std::numeric_limits<Uint32>::max)();
			controller->on = 0;
			controller->release = 0;
			controller->old = 0;
			controller->l = 0;
			controller->r = 0;
			controller->x1 = 0;
			controller->y1 = 0;
			controller->x2 = 0;
			controller->y2 = 0;
		}
	}
}

__declspec(dllexport) void __cdecl OnExit() {
	discord.reset();
}

__declspec(dllexport) ModInfo SA2ModInfo{ ModLoaderVer };
}
