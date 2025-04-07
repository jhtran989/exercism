#include "knapsack.h"

#include <vector>
#include <set>
#include <algorithm>


namespace knapsack {

// TODO: add your solution here

int maximum_value(int max_weight, const std::vector<knapsack::Item>& items_vec) {
    typedef std::set<Item> set_item_type;
    set_item_type items_set(items_vec.begin(), items_vec.end());
    //typedef std::vector<knapsack::Item> vec_item;
    std::vector<std::vector<set_item_type>> grid{};
    
    int num_items = items_vec.size();

    grid.push_back({});
    std::vector<set_item_type> emptyRow(max_weight);
    grid[0] = emptyRow;

    auto compareItems = [](Item item1, Item item2){
        return item1.value < item2.value;
    };

    // initial row
    for (int j = 0; j < max_weight; j++) {
        set_item_type temp_items{};
        std::copy_if(items_set.begin(), items_set.end(), std::back_inserter(temp_items), 
        [j](Item item){
            return item.weight == (j + 1);
        });

        if (temp_items.empty()) {
            if (j == 0) {
                grid[0][0] = {};
            } else {
                grid[0][j] = grid[0][j - 1];
            }
        } else {
            if (j == 0) {
                grid[0][0] = {*std::max_element(temp_items.begin(), temp_items.end(), compareItems)};
            } else {
                grid[0][j] = {std::max(*std::max_element(temp_items.begin(), temp_items.end(), compareItems), grid[0][j - 1][0]);}
            }
        }
        // grid[0][j] = std::max_element()
    }

    for (int i = 0; i < num_items; i++) {
        grid.push_back({});

        for (int j = 0; j < max_weight; j++) {
            int rem_weight = max_weight - (j + 1);

            
        }
    }
}

}  // namespace knapsack
