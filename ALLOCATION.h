#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <vector>
#include "RESERVATION.h"
#include "ROOMLEVEL.h"
#include "ROOM.h"

string findAvailableRoom(vector<Room>& rooms, const string &requestedType, int currentTime);
string findUpgradeRoom(vector<Room>& rooms, const string &requestedType, int currentTime);
bool allocateRoom(Reservation &res, vector<Room>& rooms, int currentTime);

#endif