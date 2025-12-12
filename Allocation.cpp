#include "ALLOCATION.h"
#include "ROOM.h"


string findAvailableRoom(vector<Room>& rooms, const string &requestedType, int currentTime) {
    for (auto &room : rooms) {
        if (room.getRoomType() == requestedType &&
            room.isAvailable() &&
            room.getNextFreeTime() == currentTime) {
            return room.getRoomID();
        }
    }
    return "";
}

string findUpgradeRoom(vector<Room>& rooms, const string &requestedType, int currentTime) {
    RoomLevel reqLevel = getRoomLevel(requestedType);

    for (int level = reqLevel + 1; level <= FAMILY_L; ++level) {
        for (auto &room : rooms) {
            if (getRoomLevel(room.getRoomType()) == level &&
                room.isAvailable() &&
                room.getNextFreeTime() <= currentTime) {
                return room.getRoomID();
            }
        }
    }
    return "";
}

bool allocateRoom(Reservation &res, vector<Room>& rooms, int currentTime) {

    // release expired rooms
    for (auto &r : rooms) r.tryFree(currentTime);

    string requestedType = res.getRequestedRoomType();
    string customerType = res.getCustomerType();

    string roomID = findAvailableRoom(rooms, requestedType, currentTime);

    if (roomID != "") {
        res.assignRoom(roomID);
        res.setCheckInTime(currentTime);
        res.calculateCheckOutTime();

        for (auto &room : rooms) {
            if (room.getRoomID() == roomID)
                room.assignToReservation(res.getID(), currentTime, res.getCheckOutTime());
        }
        return true;
    }

    if (customerType == "VIP") {
        roomID = findUpgradeRoom(rooms, requestedType, currentTime);

        if (roomID != "") {
            string newType = "";
            for (auto &room : rooms) {
                if (room.getRoomID() == roomID) newType = room.getRoomType();
            }

            res.assignRoom(roomID);
            res.setCheckInTime(currentTime);
            res.upgrade(newType);
            res.calculateCheckOutTime();

            for (auto &room : rooms) {
                if (room.getRoomID() == roomID)
                    room.assignToReservation(res.getID(), currentTime, res.getCheckOutTime());
            }
            return true;
        }
    }

    return false;
}