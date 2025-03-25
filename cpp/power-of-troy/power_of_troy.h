#pragma once

#include <string>

// PERSONAL
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

    struct human {
        std::unique_ptr<artifact> possession;
        std::shared_ptr<power> own_power;
        std::shared_ptr<power> influenced_by;
        
        // human() : 
        // possession(std::make_unique<artifact>(nullptr)),
        // own_power(std::make_shared<power>(nullptr)),
        // influenced_by(std::make_shared<power>(nullptr)) {}

        human() : 
        possession(nullptr),
        own_power(nullptr),
        influenced_by(nullptr) {}
 
        
    };

    void give_new_artifact(human& some_human, std::string str);
    void exchange_artifacts(std::unique_ptr<artifact>& sp_art1, std::unique_ptr<artifact>& sp_art2);
    void manifest_power(human& some_human, std::string str);
    void use_power(human& caster, human& target);
    int power_intensity(human& some_human);

    // void give_new_artifact(human& some_human, std::string str) {
    //     some_human.possession = std::make_unique<artifact>(artifact(str));
    // }

    // void exchange_artifacts(std::unique_ptr<artifact>& sp_art1, std::unique_ptr<artifact>& sp_art2) {
    //     std::swap(sp_art1, sp_art2);
    // }

    // void manifest_power(human& some_human, std::string str) {
    //     some_human.own_power = std::make_shared<power>(power(str));
    // }

    // void use_power(human& caster, human& target) {
    //     target.influenced_by = caster.influenced_by;
    // }

    // int power_intensity(human& some_human) {
    //     if (!some_human.own_power) {
    //         return 0;
    //     } else {
    //         return some_human.own_power.use_count();
    //     }
    // }

}  // namespace troy
