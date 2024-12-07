#pragma once

#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// General parsers
std::vector<std::vector<char>> parse_2d_char_vec(std::string file);
std::vector<std::vector<int>> parse_2d_int_vec(std::string file);
std::string parse_string(std::string file);

// Specific parsers
std::vector<std::vector<int>> parse_2_int_cols(std::string file);
std::pair<std::unordered_map<int, std::unordered_set<int>>, std::vector<std::vector<int>>> parse_page_ordering(std::string file);
std::vector<std::vector<long>> parse_bridge_repair(std::string file);
