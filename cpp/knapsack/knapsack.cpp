#include "knapsack.h"

#include <vector>
#include <set>
#include <algorithm>


namespace knapsack {

// TODO: add your solution here

int maximum_value(int max_weight, const std::vector<knapsack::Item>& items_vec) {
    int num_items = items_vec.size();
    std::vector<std::vector<int>> grid(num_items + 1, std::vector<int>(max_weight + 1));

    // 0s along top row and left column
    for (int i = 0; i < num_items + 1; i++) {
        for (int j = 0; j < max_weight + 1; j++) {
            // base case
            if (i == 0 || j == 0) {
                grid[i][j] = 0;
            } else {
                // choose (i - 1)th item (from 0 indexing)
                int add_weight{0};

                // weight from 1 to max_weight
                // index into items is 1 to num_items (but to convert index 0 to num_items - 1)
                int curr_weight = items_vec[i - 1].weight;
                if (curr_weight <= j) {
                    add_weight = items_vec[i - 1].value + grid[i - 1][j - curr_weight];
                }

                int not_add_weight{grid[i - 1][j]};

                grid[i][j] = std::max(add_weight, not_add_weight);
            }
        }
    }

    return grid[num_items][max_weight];
}

}  // namespace knapsack
