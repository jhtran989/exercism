// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

// hp4,ölacöiömthö%Äsmaö%Äsubö(311040ö%Äspaö%Äaddö(311040ö%Ädacöiömthö%Äcountö.hpt,hp4ö%Äxctöhd2ö%Ädacöiöma1
// hp2,öjmpö.

#include "doctor_data.h"
#include <string>

// FIXME: just put class definition in header...
namespace heaven {
    // class Vessel {
    // // private:
        
    // public:
    //     std::string name;
    //     int generation;
    //     star_map::System current_system;
    //     int busters;

    //     Vessel(std::string name, int generation) : name(name), generation(generation) {}
    //     Vessel(std::string name, int generation, star_map::System current_system) : name(name), generation(generation), current_system(current_system) {}

    //     Vessel replicate(std::string name) {
    //         return Vessel{name, 2, star_map::System::Sol};
    //     }
        
    //     void make_buster() {
    //         busters++;
    //     }

    //     bool shoot_buster() {
    //         if (busters > 0)
    //         {
    //             busters--;
    //             return true;
    //         }
            
    //         return false;
    //     }
    // };

    Vessel::Vessel(std::string name, int generation) : name(name), generation(generation) {}
    Vessel::Vessel(std::string name, int generation, star_map::System current_system) : name(name), generation(generation), current_system(current_system) {}

    Vessel Vessel::replicate(std::string name) {
        return Vessel{name, 2, star_map::System::Sol};
    }
    
    void Vessel::make_buster() {
        busters++;
    }

    bool Vessel::shoot_buster() {
        if (busters > 0)
        {
            busters--;
            return true;
        }
        
        return false;
    }

    std::string get_older_bob(Vessel vessel1, Vessel vessel2) {
        if (vessel1.generation < vessel2.generation) {
            return vessel1.name;
        } else {
            return vessel2.name;
        }
    }

    bool in_the_same_system(Vessel vessel1, Vessel vessel2) {
        return vessel1.current_system == vessel2.current_system;
    }
}



