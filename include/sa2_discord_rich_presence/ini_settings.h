#pragma once
#include <filesystem>

// todo: is this file needed? you could just query the IniFile every time you
// need information. You already do this when checking other mod's ini files.

namespace ini {
	/// enables free cam toggle, freeze toggle and load cutscene from clipboard
	/// with more notes and controls in 'free_cam.h'.
	extern bool debug_mode;
	/// whether to output to log on rich presence update. Default: true
	extern bool log_on_rpc_update;
	/// whether to use the player's chao name during race or karate. Default: true
	extern bool chao_names;

	/// load settings from ini file
	void load(const std::filesystem::path& path);
} // namespace ini
