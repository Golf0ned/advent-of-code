#include <iostream>
#include <regex>

#include "../utils/aoc_parser.h"

int part_1(std::string memory) {
    std::regex re("mul\\(\\d+,\\d+\\)");
    auto regex_begin = std::sregex_iterator(memory.begin(), memory.end(), re);
    auto regex_end = std::sregex_iterator();

    int res = 0;

    for (auto iter = regex_begin; iter != regex_end; iter++) {
        std::string cur = iter->str(); // mul(<num1>,<num2>)
        int num1 = std::stoi(cur.substr(4, cur.find(',')));
        int num2 = std::stoi(cur.substr(cur.find(',') + 1, cur.size() - 1));
        res += num1 * num2;
    }

    return res;
}

int main(int argc, char* argv[]) {
    try {
        std::string input = parse_string(argv[1]);
        int res = part_1(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
