#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

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

std::vector<std::vector<int>> parse_input(std::string file) {
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::string line;
    std::vector<std::vector<int>> input(2, std::vector<int>());

    while (std::getline(inFile, line)) {
        std::istringstream stream(line);
        int num1, num2;
        if (stream >> num1 >> num2) {
            input[0].push_back(num1);
            input[1].push_back(num2);
        }
    }

    inFile.close();

    return input;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<int>> input = parse_input(argv[1]);
        int res = part_1(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

