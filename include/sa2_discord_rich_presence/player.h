#pragma once
#include <cstddef>
#include <string>

/// this function returns the player index that is currently being controlled.
/// in final hazard, player 0 controls both players, alternating between them
std::size_t current_player(std::size_t player);

/// returns a string with the number of rings and lives for a player
/// \param player the player to get the rings and lives from
/// \param show_lives whether to show the lives or not, as it may not be
/// relevant for some levels
std::string current_player_state(std::size_t player);
