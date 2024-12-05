#pragma once

#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::vector<int>> parse_2_int_cols(std::string file);
std::vector<std::vector<int>> parse_2d_int_vec(std::string file);
std::string parse_string(std::string file);
