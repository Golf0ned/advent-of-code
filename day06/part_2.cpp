#include <iostream>
#include <set>
#include <vector>

#include "../utils/aoc_parser.h"

bool has_loop(std::vector<std::vector<char>> &input, int start_row, int start_col) {
    int rows = input.size(), cols = input[0].size();
    int dirs[] = {-1, 0, 1, 0, -1};

    int row = start_row, col = start_col, dir = 0;
    std::set<std::vector<int>> visited;
    while (true) {
        if (visited.find({row, col, dir}) != visited.end()) {
            return true;
        }

        int next_row = row + dirs[dir], next_col = col + dirs[dir + 1];

        if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols) {
            return false;
        }
        else if (input[next_row][next_col] == '#') {
            visited.insert({row, col, dir});
            dir = (dir + 1) % 4;
        }
        else {
            row = next_row;
            col = next_col;
        }
    }
}

int part_2(std::vector<std::vector<char>> &input) {
    int rows = input.size(), cols = input[0].size();
    int dirs[] = {-1, 0, 1, 0, -1};

    int start_row, start_col;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (input[i][j] == '^') {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    int row = start_row, col = start_col, dir = 0;
    int res = 0;
    std::set<std::vector<int>> visited;
    while (true) {
        int next_row = row + dirs[dir], next_col = col + dirs[dir + 1];
        if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols) {
            break;
        }

        if (input[next_row][next_col] == '#') {
            dir = (dir + 1) % 4;
            continue;
        }
        
        if (input[next_row][next_col] != '^' && visited.find({next_row, next_col}) == visited.end()) {
            std::vector<std::vector<char>> copy = input;
            copy[next_row][next_col] = '#';
            if (has_loop(copy, start_row, start_col)) {
                res++;
            }
        }
        
        visited.insert({next_row, next_col});
        row = next_row;
        col = next_col;
    }

    return res;
}

int main(int argc, char *argv[]) {
    try {
        std::vector<std::vector<char>> input = parse_2d_char_vec(argv[1]);
        int res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
