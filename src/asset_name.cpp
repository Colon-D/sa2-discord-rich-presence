#include "sa2_discord_rich_presence/asset_name.h"

std::string asset_name(std::string asset_name) {
	// convert level name to lowercase, replace spaces with underscores,
	for (auto& c : asset_name) {
		if (c == ' ') {
			c = '_';
		} else {
			c = static_cast<char>(std::tolower(+c));
		}
	}
	// remove any non-alphanumeric characters not including _ or -
	asset_name.erase(
		std::remove_if(
			asset_name.begin(),
			asset_name.end(),
			[](const char c) {
				return (std::isalnum(c) == 0) && (c != '_') && (c != '-');
			}
		),
		asset_name.end()
	);

	return asset_name;
}
