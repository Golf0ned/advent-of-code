#include <fstream>
#include <sstream>
#include <vector>

//
// General parsers
//

// 2d char vector
std::vector<std::vector<char>> parse_2d_char_vec(std::string file) {
    std::vector<std::vector<char>> input;

    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::string line;
    while (std::getline(inFile, line)) {
        input.emplace_back(line.begin(), line.end());
    }

    inFile.close();
    return input;
}

// 2d int vector
std::vector<std::vector<int>> parse_2d_int_vec(std::string file) {
    std::vector<std::vector<int>> input;

    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<int> row;
        std::istringstream stream(line);
        int num;
        while (stream >> num) {
            row.push_back(num);
        }
        input.push_back(row);
    }

    inFile.close();
    return input;
}

// string
std::string parse_string(std::string file) {
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string input = buffer.str();

    inFile.close();
    return input;
}

//
// Specific parsers
//

// 2 int columns (day 1)
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
