#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "../utils/aoc_parser.h"

int part_1(std::vector<std::vector<int>> input) {
    int res = 0;
    std::vector<int> nums1 = input[0];
    std::sort(nums1.begin(), nums1.end());

    std::vector<int> nums2 = input[1];
    std::sort(nums2.begin(), nums2.end());

    for (int i = 0; i < nums1.size(); i++) {
        res += std::abs(nums1[i] - nums2[i]);
    }

    return res;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<int>> input = parse_2_int_cols(argv[1]);
        int res = part_1(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

