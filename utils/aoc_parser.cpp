#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::vector<int>> parse_2_int_cols(std::string file) {
    std::vector<std::vector<int>> input(2);

    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::string line;
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