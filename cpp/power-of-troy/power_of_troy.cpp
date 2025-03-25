#include "power_of_troy.h"

namespace troy {
    void give_new_artifact(human& some_human, std::string str) {
        some_human.possession = std::make_unique<artifact>(artifact(str));
    }

    void exchange_artifacts(std::unique_ptr<artifact>& sp_art1, std::unique_ptr<artifact>& sp_art2) {
        std::swap(sp_art1, sp_art2);
    }

    void manifest_power(human& some_human, std::string str) {
        some_human.own_power = std::make_shared<power>(power(str));
    }

    void use_power(human& caster, human& target) {
        target.influenced_by = caster.own_power;
    }

    int power_intensity(human& some_human) {
        if (!some_human.own_power) {
            return 0;
        } else {
            return some_human.own_power.use_count();
        }
    }
}  // namespace troy





