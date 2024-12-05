#include <iostream>
#include <unordered_map>
#include <vector>

#include "../utils/aoc_parser.h"

int part_2(std::vector<std::vector<int>> input) {
    std::unordered_map<int, int> count;
    for (int i : input[1]) {
        count[i] = count[i] + 1;
    }
    
    int res = 0;
    for (int i : input[0]) {
        res += i * count[i];
    }
    return res;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<int>> input = parse_2_int_cols(argv[1]);
        int res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

