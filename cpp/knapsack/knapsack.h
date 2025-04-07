#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>

namespace knapsack {

struct Item {
    int weight;
    int value;
};

int maximum_value(int max_weight, const std::vector<knapsack::Item>& items_vec);

}  // namespace knapsack

#endif  // KNAPSACK_H
