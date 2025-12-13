// =================== Restaurant System ===================
#include <bits/stdc++.h>
#include "RestaurantSystem.h"
using namespace std;

void runRestaurantSystem() {
    RestaurantSystem R;
    R.vipChefs.push_back(new Chef(1, Chef_VIP, 3));
    R.normalChefs.push_back(new Chef(2, Chef_NORMAL, 2));
    R.veganChefs.push_back(new Chef(3, Chef_VEGAN, 1));

    R.addOrder(new Order(100, VIP, 5, 450, 1));
    R.addOrder(new Order(101, NORMAL, 3, 600, 1));
    R.addOrder(new Order(102, VEGAN, 6, 200, 1));
    R.addOrder(new Order(103, VIP, 2, 150, 1));
    R.addOrder(new Order(104, NORMAL, 4, 700, 1));
    R.addOrder(new Order(105, VEGAN, 3, 300, 1));
    R.addOrder(new Order(106, NORMAL, 7, 800, 1));

    int time = 1;

    while (true) {
        cout << "\n--- Time = " << time << " ---\n";

        R.updateChefs();
        R.assignOrder(time);

        bool stillOrders =
            !R.normalQ.empty() ||
            !R.veganQ.empty()  ||
            !R.vipList.empty();

        bool chefsBusy = false;
        for (auto c : R.vipChefs) if (c->busy) chefsBusy = true;
        for (auto c : R.normalChefs) if (c->busy) chefsBusy = true;
        for (auto c : R.veganChefs) if (c->busy) chefsBusy = true;

        if (!stillOrders && !chefsBusy)
            break;

        time++;
   }
}

// =================== Reservation & Room System ===================
#include <iostream>
#include "RESERVATION.h"
#include "ROOMLEVEL.h"
#include "ALLOCATION.h"
#include "ROOM.h"
#include <vector>

using namespace std;

void runReservationSystem() {
    cout << "=== Integrated Hotel System ===" << endl << endl;

    vector<Room> rooms = {
        Room("Single-101", "Single"),
        Room("Single-102", "Single"),
        Room("Double-201", "Double"),
        Room("Double-202", "Double"),
        Room("Deluxe-301", "Deluxe"),
        Room("Deluxe-302", "Deluxe"),
        Room("Suite-401", "Suite"),
        Room("Suite-402", "Suite"),
        Room("Family-501", "Family"),
        Room("Standard-601", "Standard"),
        Room("Ecomomy-701", "Economy")
    };

    Reservation res1(1, "VIP", 10, 3, "Double");   
    Reservation res2(2, "REG", 12, 2, "Single");
    Reservation res3(3, "ECO", 15, 1, "Single");   

    cout << "Initial Reservations (Before Allocation):" << endl;
    res1.print();
    res2.print();
    res3.print();

    bool a1 = allocateRoom(res1, rooms, res1.getArrivalTime()); 
    bool a2 = allocateRoom(res2, rooms, res2.getArrivalTime());
    bool a3 = allocateRoom(res3, rooms, res3.getArrivalTime());

    cout << "\nAllocation Results:" << endl;

    if (a1) {
        cout << "\nReservationOne (VIP) allocated successfully:" << endl;
        res1.print();
    } else {
        cout << "\nReservationOne (VIP) not allocated, added to queue." << endl;
    }

    if (a2) {
        cout << "\nReservationTwo (REG) allocated successfully:" << endl;
        res2.print();
    } else {
        cout << "\nReservationTwo (REG) not allocated, added to queue." << endl;
    }

    if (a3) {
        cout << "\nReservationThree (ECO) allocated successfully:" << endl;
        res3.print();
    } else {
        cout << "\nReservationThree (ECO) not allocated, added to queue." << endl;
    }

    cout << "\nRoom statuses after allocation (RoomID : Type - NextFreeTime - IsAvailable):" << endl;
    for (auto &r : rooms) {
        cout << r.getRoomID() << " : " << r.getRoomType()
             << " - NextFreeTime=" << r.getNextFreeTime()
             << " - Available=" << (r.isAvailable() ? "YES" : "NO")
             << endl;
    }

    Reservation vipLater(10, "VIP", 13, 2, "Deluxe");
    bool a4 = allocateRoom(vipLater, rooms, vipLater.getArrivalTime());
    cout << "\nLater VIP reservation allocation attempt:" << endl;
    if (a4) vipLater.print(); else cout << "No room for later VIP." << endl;

    cout << "\n=== End of simulation ===" << endl;
}

// =================== Main واحد فقط ===================
int main() {
    // شغّل كل الأنظمة بالترتيب
    runReservationSystem();
    runRestaurantSystem();

    // لاحقًا ممكن تضيفي: runStaffSystem(); و runVehicleSystem();
    
    return 0;
}
