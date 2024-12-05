#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/aoc_parser.h"

bool is_valid_update(std::vector<int> update, std::unordered_map<int, std::unordered_set<int>> precedes) {
    std::unordered_set<int> prev;
    for (int i : update) {
        for (int j : precedes[i]) {
            if (prev.find(j) != prev.end()) {
                return false;
            }
        }
        prev.insert(i);
    }
    return true;
}

int part_1(const std::unordered_map<int, std::unordered_set<int>> &precedes,
           const std::vector<std::vector<int>> &updates) {
    int res = 0;
    for (const auto& update : updates) {
        if (is_valid_update(update, precedes)) {
            res += update[(update.size() - 1) / 2];
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    try {
        auto input = parse_page_ordering(argv[1]);
        int res = part_1(input.first, input.second);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
