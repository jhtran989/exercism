#pragma once

#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int avg_prep_time=2);

amount quantities(std::vector<std::string> layers);

void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList);

std::vector<double> scaleRecipe(std::vector<double> quantities, int portions);

void addSecretIngredient(std::vector<std::string>& myList, const std::string secret_ingredient);

}  // namespace lasagna_master
