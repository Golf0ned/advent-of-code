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

int part_1(std::vector<std::vector<int>> input) {
    int res = 0;
    for (auto& line : input) {
        if (is_safe_report(line)) {
            res++;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<int>> input = parse_2d_int_vec(argv[1]);
        int res = part_1(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
