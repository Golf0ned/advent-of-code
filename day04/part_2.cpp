#include <iostream>
#include <vector>

#include "../utils/aoc_parser.h"

int check_xmas(std::vector<std::vector<char>> input, int x, int y) {
    int x_max = input.size();
    int y_max = input[0].size();

    if (false
        || x - 1 < 0
        || x + 1 >= x_max
        || y - 1 < 0
        || y + 1 >= y_max
    ) {
        return 0;
    }

    char ul = input[x-1][y-1], ur = input[x-1][y+1], dl = input[x+1][y-1], dr = input[x+1][y+1];
    return true
        && (ul == 'M' || ul == 'S')
        && (ur == 'M' || ur == 'S')
        && (dl == 'M' || dl == 'S')
        && (dr == 'M' || dr == 'S')
        && ul != dr
        && ur != dl;
}

int part_2(std::vector<std::vector<char>> input) {
    int res = 0;
    for (int x = 0; x < input.size(); x++) {
        for (int y = 0; y < input[x].size(); y++) {
            if (input[x][y] == 'A') {
                res += check_xmas(input, x, y);
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<char>> input = parse_2d_char_vec(argv[1]);
        int res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
