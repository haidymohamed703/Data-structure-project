#ifndef ROOMLEVEL_H
#define ROOMLEVEL_H

#include <string>
using namespace std;

enum RoomLevel {
    SINGLE_L = 0,
    DOUBLE_L = 1,
    STANDARD_L = 2,
    DELUXE_L = 3,
    SUITE_L = 4,
    FAMILY_L = 5,
    ECONOMY_L = 6
};

inline RoomLevel getRoomLevel(const string &roomType) {
    string t = roomType;
    for (auto &c : t) c = tolower(c);
    
    if (t == "single") return SINGLE_L;
    if (t == "double") return DOUBLE_L;
    if (t == "standard") return STANDARD_L;
    if (t == "deluxe") return DELUXE_L;
    if (t == "suite") return SUITE_L;
    if (t == "family") return FAMILY_L;
    if (t == "economy") return ECONOMY_L;
    return SINGLE_L;
}

#endif