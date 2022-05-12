#include "sa2_discord_rich_presence/ini_settings.h"
#include <IniFile.hpp>
#include <iostream>

namespace ini {

bool debug_mode{ false };
bool log_on_rpc_update{ true };
bool chao_names{ true };

void load(const std::filesystem::path& path) {
	std::cout << "sa2-discord-rich-presence:\n";
	IniFile ini_file{ path / "config.ini" };
	if (const auto* const settings = ini_file.getGroup("Settings")) {
		debug_mode = settings->getBool("Debug Mode", false);
		log_on_rpc_update = settings->getBool("Log on RPC Update", true);
		chao_names = settings->getBool("Chao Names", true);
		std::cout << "\tloaded config.ini\n";
	}
	else {
		std::cout << "\tcould not load config.ini\n";
	}
}

} // namespace ini
