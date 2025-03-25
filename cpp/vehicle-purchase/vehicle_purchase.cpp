#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    // TODO: Return true if you need a license for that kind of vehicle.

    if (kind == "car" || kind == "truck") {
        return true;
    } else {
        return false;
    }
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    // TODO: Return the final decision in a sentence.

    std::string better = option1 < option2 ? option1 : option2;
    return better + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    // TODO: Return the age-corrected resell price.
    
    double discount;
    if (age < 3) {
        discount = 0.8;
    } else if (age < 10) {
        discount = 0.7;
    } else {
        discount = 0.5;
    }

    return discount * original_price;
}

}  // namespace vehicle_purchase