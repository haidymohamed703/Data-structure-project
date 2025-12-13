#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

class Room {
private:
    string RoomID;
    string Type;
    bool IsAvailable;
    int NextFreeTime;
    int CurrentReservationID;

public:
    Room(string id, string t, bool available = true)
        : RoomID(id), Type(t), IsAvailable(available),
          NextFreeTime(0), CurrentReservationID(-1) {}

    string getRoomID() const { return RoomID; }
    string getRoomType() const { return Type; }
    bool isAvailable() const { return IsAvailable; }
    int getNextFreeTime() const { return NextFreeTime; }

    void assignToReservation(int resID, int start, int end) {
        IsAvailable = false;
        CurrentReservationID = resID;
        NextFreeTime = end;
    }

    void tryFree(int currentTime) {
        if (!IsAvailable && NextFreeTime <= currentTime) {
            IsAvailable = true;
            CurrentReservationID = -1;
        }
    }
};

#endif
