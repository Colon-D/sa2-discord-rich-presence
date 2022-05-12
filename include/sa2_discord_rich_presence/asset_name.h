#pragma once
#include <string>
#include <unordered_set>

/// converts string similar to how discord converts asset names to string,
/// but not exactly the same.
/// check for a more specialized version (ie x_asset_name()) as additional
/// transformations might need to be applied to get the asset name.
/// (convert to lowercase, convert spaces to underscores, remove
/// non-alphanumeric characters (apart from _ and -))
std::string asset_name(std::string asset_name);
