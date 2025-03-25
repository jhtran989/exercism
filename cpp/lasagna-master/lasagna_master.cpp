#include "lasagna_master.h"

#include <algorithm>

using std::string;
using std::vector;

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(std::vector<std::string> layers, int avg_prep_time) {
    return layers.size() * avg_prep_time;
}

amount quantities(std::vector<std::string> layers) {
    int noodles_layers{};
    noodles_layers = std::count_if(layers.begin(), layers.end(), 
    [](string layer){
        return layer == "noodles";
    });

    int sauce_layers{};
    sauce_layers = std::count_if(layers.begin(), layers.end(),
    [](string layer){
        return layer == "sauce";
    }); 

    return amount{noodles_layers * 50, sauce_layers * 0.2};
}

// FIXME: remember to have a REFERENCE when calling front() or back()
void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList) {
    string& myListLast = myList.back();
    myListLast = friendsList.back();
}

std::vector<double> scaleRecipe(std::vector<double> quantities, int portions) {
    vector<double> new_quantities{};
    double servings{static_cast<double>(portions) / 2};

    std::transform(quantities.begin(), quantities.end(), std::back_inserter(new_quantities), 
    [&servings](double quantity){
        return quantity * servings;
    });

    return new_quantities;
}

void addSecretIngredient(std::vector<std::string>& myList, const std::string secret_ingredient) {
    string& myListLast = myList.back();
    myListLast = secret_ingredient;
}

}  // namespace lasagna_master
