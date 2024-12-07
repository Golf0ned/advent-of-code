#include <iostream>
#include <vector>

#include "../utils/aoc_parser.h"

bool calibratable(long val, const std::vector<long> &row, int depth, long cur) {
    if (depth >= row.size()) {
        return cur == val;
    }
    if (depth > 1 && cur == 0) {
        return false;
    }
    long concat = std::stol(std::to_string(cur) + std::to_string(row[depth]));
    return (false
            || calibratable(val, row, depth + 1, cur + row[depth])
            || calibratable(val, row, depth + 1, cur * row[depth])
            || calibratable(val, row, depth + 1, concat)
            );
}

long part_2(std::vector<std::vector<long>> &input) {
    long res = 0;
    for (const auto &row : input) {
        long val = row[0];
        
        if (calibratable(val, row, 1, 0)) {
            res += val;
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    try {
        std::vector<std::vector<long>> input = parse_bridge_repair(argv[1]);
        long res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
