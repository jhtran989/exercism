#include "spiral_matrix.h"

#include <vector>
#include <array>
#include <iostream>

// for assert
#include <cassert>

// for tie
#include <tuple>

#define assertm(exp, msg) assert((void(msg), exp))

namespace spiral_matrix {

std::vector<std::array<int, 2>> direction_index = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

void printFinalMatrix(std::vector<std::vector<uint>>& final_matrix) {
    for (auto& row : final_matrix) {
        for (auto& value : row) {
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

// TODO: add your solution here
std::vector<std::vector<uint>> spiral_matrix(int n) {
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    std::vector<std::vector<uint>> final_matrix(n, std::vector<uint>(n, 0));

    //assertm(n > 0, "Cannot handle case where n == 0...");
    if (n == 0) {
        return {};
    }

    int row{0};
    int column{0};
    int newRow;
    int newColumn;
    int counter{1};
    int direction{0};
    auto [row_delta, column_delta] = direction_index[direction];
    int numSwitchDirection{0};

    final_matrix[0][0] = counter;
    counter++;

    printFinalMatrix(final_matrix);


    while (true) {
        // if after two successive direction changes, then everything should be filled
        if (numSwitchDirection == 2) {
            break;
        }

        newRow = row + row_delta;
        newColumn = column + column_delta;

        std::cout << "new row: " << newRow << std::endl;
        std::cout << "new column: " << newColumn << std::endl;

        // TODO: need to check if unvisited
        if (newRow >= 0 && newRow < n && newColumn >= 0 && newColumn < n && final_matrix[newRow][newColumn] == 0) {
            final_matrix[newRow][newColumn] = counter;
            counter++;

            numSwitchDirection = 0;

            row = newRow;
            column = newColumn;

            printFinalMatrix(final_matrix);
        } else {
            direction = (direction + 1) % 4;
            numSwitchDirection++;

            // TODO: structured bindings does NOT work for existing vars?
            auto curr_direction = direction_index[direction];
            row_delta = curr_direction[0];
            column_delta = curr_direction[1];
        }
    }

    return final_matrix;
}

}  // namespace spiral_matrix
