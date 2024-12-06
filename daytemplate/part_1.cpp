#include <iostream>

#include "../utils/aoc_parser.h"

int part_1() {
    int res = 0;
    return res;
}

int main(int argc, char *argv[]) {
    try {
        int res = part_1();
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
