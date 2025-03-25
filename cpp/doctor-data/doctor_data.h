// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

// hp1, üapöhp2ö % Äcountöiöma1,
//     öhp2ö % Älawöhp3öö / önextöstepö % Ädacöiöml1ö % Älawö7ö % Ädacöiömb1ö %
//         Ärandomöö % Äscrö9sö % Äsirö9sö % Äxctöhr1ö % Äaddöiömx1ö %
//         Ädacöiömx1ö % Äswapö % Äaddöiömy1ö % Ädacöiömy1ö % Ärandomö % Äscrö9sö %
//         Äsirö9sö % Äxctöhr2ö % Ädacöiömdyö % Ädioöiömdxö % Äsetupö.hpt,
//     3ö % Älacöranö % Ädacöiömth

#pragma once
#include <string>

namespace star_map {
    enum class System {
        Sol,
        AlphaCentauri,
        BetaHydri,
        DeltaEridani,
        EpsilonEridani,
        Omicron2Eridani,
    };
}

namespace heaven {
    class Vessel {
    // private:
    //     std::string str;
    public:
        std::string name;
        int generation;
        star_map::System current_system;
        int busters{0};

        Vessel(std::string str, int generation);
        Vessel(std::string str, int generation, star_map::System current_system);

        Vessel replicate(std::string str);
        
        void make_buster();
        bool shoot_buster();
    };

    std::string get_older_bob(Vessel vessel1, Vessel vessel2);
    bool in_the_same_system(Vessel vessel1, Vessel vessel2);
}

