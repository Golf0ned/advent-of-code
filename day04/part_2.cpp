#include <fstream>
#include <iostream>
#include <vector>

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

std::vector<std::vector<char>> parse_input(std::string file) {
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::vector<std::vector<char>> input;
    std::string line;

    while (std::getline(inFile, line)) {
        input.emplace_back(line.begin(), line.end());
    }

    inFile.close();
    return input;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::vector<char>> input = parse_input(argv[1]);
        int res = part_2(input);
        std::cout << res << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
