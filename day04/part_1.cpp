#include <iostream>
#include <vector>

#include "../utils/aoc_parser.h"

int check_xmas(std::vector<std::vector<char>> input, int x, int y) {
    int res = 0;
    int x_max = input.size();
    int y_max = input[0].size();

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (true
                && x + 3*dx >= 0
                && x + 3*dx < x_max
                && y + 3*dy >= 0
                && y + 3*dy < y_max
                && input[x+dx][y+dy] == 'M'
                && input[x+2*dx][y+2*dy] == 'A'
                && input[x+3*dx][y+3*dy] == 'S'
            ) {
                res++;
            }
        }
    }

    return res;
}

int part_1(std::vector<std::vector<char>> input) {
    int res = 0;
    for (int x = 0; x < input.size(); x++) {
        for (int y = 0; y < input[x].size(); y++) {
            if (input[x][y] == 'X') {
                res += check_xmas(input, x, y);
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<char>> input = parse_2d_char_vec(argv[1]);
        int res = part_1(input);
        std::cout << res << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
