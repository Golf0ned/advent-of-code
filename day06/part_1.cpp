#include <iostream>
#include <vector>

#include "../utils/aoc_parser.h"

int part_1(std::vector<std::vector<char>> &input) {
    int rows = input.size(), cols = input[0].size();

    int dirs[] = {-1, 0, 1, 0, -1};

    int row, col;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (input[i][j] == '^') {
                row = i;
                col = j;
                break;
            }
        }
    }

    int dir = 0;
    while (true) {
        int next_row = row + dirs[dir], next_col = col + dirs[dir + 1];
        
        if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols) {
            // out of bounds: exit
            input[row][col] = 'X';
            break;
        }
        else if (input[next_row][next_col] == '#') {
            // #: turn
            dir = (dir + 1) % 4;
            continue;
        }
        else {
            // . or X: move forward
            input[row][col] = 'X';
            row = next_row;
            col = next_col;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << input[i][j];
        }
        std::cout << std::endl;
    }

    int res = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (input[i][j] == 'X') {
                res++;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    try {
        std::vector<std::vector<char>> input = parse_2d_char_vec(argv[1]);
        int res = part_1(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
