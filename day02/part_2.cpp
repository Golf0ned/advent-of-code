#include <iostream>
#include <vector>

#include "../utils/aoc_parser.h"

bool is_safe_report(const std::vector<int>& row) {
    if (row.empty()) {
        return false;
    }
    bool increasing = row[1] > row[0];
    for (int i = 1; i < row.size(); i++) {
        int diff = increasing ? row[i] - row[i-1] : row[i-1] - row[i];
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

int part_2(std::vector<std::vector<int>> input) {
    int res = 0;
    for (auto& line : input) {
        // yes, this is lazy, but the input's small enough that i don't really care
        bool is_safe = is_safe_report(line);
        if (!is_safe) {
            for (int i = 0; i < line.size(); i++) {
                std::vector<int> copy = line;
                copy.erase(copy.begin() + i);
                if (is_safe_report(copy)) {
                    res++;
                    break;
                }
            }
        }
        else {
            res++;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<int>> input = parse_2d_int_vec(argv[1]);
        int res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
