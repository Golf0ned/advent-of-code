#include <fstream>
#include <iostream>
#include <regex>

int part_2(std::string memory) {
    std::regex re("mul\\(\\d+,\\d+\\)|do(n't)?\\(\\)");
    auto regex_begin = std::sregex_iterator(memory.begin(), memory.end(), re);
    auto regex_end = std::sregex_iterator();

    int res = 0;
    bool enabled = true;
    for (auto iter = regex_begin; iter != regex_end; iter++) {
        std::string cur = iter->str();
        if (cur == "do()") {          // do()
            enabled = true;
        }
        else if (cur == "don\'t()") {  // don't()
            enabled = false;
        }
        else {                        // mul(<num1>,<num2>)
            if (!enabled) {
                continue;
            }
            int num1 = std::stoi(cur.substr(4, cur.find(',')));
            int num2 = std::stoi(cur.substr(cur.find(',') + 1, cur.size() - 1));
            res += num1 * num2;
        }
    }

    return res;
}

std::string parse_input(std::string file) {
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

int main(int argc, char* argv[]) {
    try {
        std::string input = parse_input(argv[1]);
        int res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
