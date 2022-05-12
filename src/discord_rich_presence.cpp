#include "sa2_discord_rich_presence/discord_rich_presence.h"
#include "sa2_discord_rich_presence/ini_settings.h"
#include <discord_rpc.h>
#include <iostream>

discord::discord() {
	std::cout << "sa2-discord-rich-presence:\n";
	std::cout << "\tdiscord::discord():\n";
	std::cout << "\t\tInitializing Discord.\n";
	constexpr const char* client_id    { "961322317592539177" };
	constexpr const char* steam_id     { "213610" };
	constexpr int         auto_register{ 0 };
	Discord_Initialize(client_id, nullptr, auto_register, steam_id);
	std::cout << "\t\tInitialized Discord.\n";
}

discord::~discord() {
	std::cout << "sa2-discord-rich-presence:\n";
	std::cout << "\tdiscord::~discord():\n";
	std::cout << "\t\tShutting down Discord.\n";
	Discord_Shutdown();
	std::cout << "\t\tShut down Discord.\n";
}

void discord::update_discord_if_changed_and_not_empty() {
	if (approximately_equal(rpc, {}) || approximately_equal(rpc, prev_rpc)) {
		return;
	}

	prev_rpc = rpc;

	DiscordRichPresence discord_rich_presence{};
	discord_rich_presence.details        = rpc.details.c_str();
	discord_rich_presence.state          = rpc.state.c_str();
	discord_rich_presence.largeImageKey  = rpc.large_image_key.c_str();
	discord_rich_presence.largeImageText = rpc.large_image_text.c_str();
	discord_rich_presence.smallImageKey  = rpc.small_image_key.c_str();
	discord_rich_presence.smallImageText = rpc.small_image_text.c_str();
	using namespace std::chrono;
	discord_rich_presence.startTimestamp =
		duration_cast<seconds>(rpc.start_timestamp.time_since_epoch()).count();
	discord_rich_presence.endTimestamp =
		duration_cast<seconds>(rpc.end_timestamp.time_since_epoch()).count();
	Discord_UpdatePresence(&discord_rich_presence);

	if (ini::log_on_rpc_update) {
		std::cout << "sa2-discord-rich-presence:\n";
		std::cout << "\tdiscord::update_discord_if_changed_and_not_empty:\n";
		std::cout << "\t\trpc: "
			<< rpc << '\n';
	}
}

// check if time points are within two seconds of each other
// Duration will sometimes be off by at most 1 second
// (hopefully), the ingame clock will not match the system's clock exactly
template<typename clock, typename duration>
bool approximately_equal(
	const std::chrono::time_point<clock, duration> lhs,
	const std::chrono::time_point<clock, duration> rhs
) {
	return abs(lhs - rhs) < std::chrono::seconds{ 2 };
}

// timestamps are compared using timestamps_are_approximately_equal, thus this
// function is not exactly equals
bool approximately_equal(
	const discord::rich_presence& lhs,
	const discord::rich_presence& rhs
) {
	return lhs.details          == rhs.details
		&& lhs.state            == rhs.state
		&& lhs.large_image_key  == rhs.large_image_key
		&& lhs.large_image_text == rhs.large_image_text
		&& lhs.small_image_key  == rhs.small_image_key
		&& lhs.small_image_text == rhs.small_image_text
		&& approximately_equal(lhs.start_timestamp, rhs.start_timestamp)
		&& approximately_equal(lhs.end_timestamp, rhs.end_timestamp);
}

std::ostream& operator<<(
	std::ostream& ostream, const discord::rich_presence& discord_rich_presence
) {
	using namespace std::chrono;
	return ostream
		<< "{ "
		<< "details:" << discord_rich_presence.details
		<< ", state:" << discord_rich_presence.state
		<< ", large_image_key:" << discord_rich_presence.large_image_key
		<< ", large_image_text:" << discord_rich_presence.large_image_text
		<< ", small_image_key:" << discord_rich_presence.small_image_key
		<< ", small_image_text:" << discord_rich_presence.small_image_text
		<< ", start_timestamp:" << duration_cast<seconds>(
			discord_rich_presence.start_timestamp.time_since_epoch()
		)
		<< ", end_timestamp:" << duration_cast<seconds>(
			discord_rich_presence.end_timestamp.time_since_epoch()
		)
		<< " }";
}
