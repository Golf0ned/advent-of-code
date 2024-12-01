#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

using input_type = std::vector<std::vector<int>>;

int part_2(input_type input) {
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

input_type parse_input(std::string file) {
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::string line;
    input_type input(2, std::vector<int>());

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
        input_type input = parse_input(argv[1]);
        int res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

