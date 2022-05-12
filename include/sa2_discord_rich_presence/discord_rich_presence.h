#pragma once
#include "sa2_discord_rich_presence/timer.h"
#include <string>

class discord {
public:
	struct rich_presence {
		/// "What the player is currently doing", the upper string
		std::string details         {};
		/// "The user's current party status", the lower string
		std::string state           {};
		std::string large_image_key {};
		std::string large_image_text{};
		std::string small_image_key {};
		std::string small_image_text{};
		time_point  start_timestamp {};
		time_point  end_timestamp   {};
	};

	discord();
	~discord();
	// non copyable/moveable
	discord(const discord&) = delete;
	discord& operator=(const discord&) = delete;
	discord(discord&&) = delete;
	discord& operator=(discord&&) = delete;

	/// does not update if empty
	/// \tparam update_function void(discord::rich_presence&)
	template<typename update_function>
	void update_rich_presence(const update_function& update) {
		update(rpc);
		update_discord_if_changed_and_not_empty();
	}
private:
	void update_discord_if_changed_and_not_empty();

	discord::rich_presence prev_rpc{};
	discord::rich_presence rpc{};
};

bool approximately_equal(
	const discord::rich_presence& lhs, const discord::rich_presence& rhs
);

/// outputs json style string
std::ostream& operator<<(
	std::ostream& ostream, const discord::rich_presence& rich_presence
);
