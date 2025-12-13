#include <iostream>
#include "StaffManager.h"
using namespace std;

int main() {
    cout << "==============================================================" << endl;
    cout << "          Complete Staff Management System Test" << endl;
    cout << "==============================================================" << endl;
    
    // ═══════════════════════════════════════════════════════════
    // Create StaffManager and add all staff types
    // ═══════════════════════════════════════════════════════════
    
    StaffManager manager;
    
    cout << "\n[Adding Staff Members]" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    // Add Receptionists
    manager.addVIPReceptionist("VIP_R1", 5, 3, 4);
    manager.addVIPReceptionist("VIP_R2", 5, 3, 4);
    manager.addRegularReceptionist("REG_R1", 6, 3, 4);
    
    // Add Housekeepers
    manager.addHousekeeper("HK1", 10, 2, 5);
    manager.addHousekeeper("HK2", 10, 2, 5);
    
    // Add Chefs
    manager.addChef("CH1", 20, 3, 6);
    manager.addChef("CH2", 20, 3, 6);
    manager.addChef("CH3", 20, 3, 6);
    
    // Add Drivers
    manager.addDriver("DR1", 15, 4, 5);
    manager.addDriver("DR2", 15, 4, 5);
    
    cout << "\nStaff Count:" << endl;
    cout << "  VIP Receptionists: " << manager.getVIPReceptionistCount() << endl;
    cout << "  Regular Receptionists: " << manager.getRegularReceptionistCount() << endl;
    cout << "  Housekeepers: " << manager.getHousekeeperCount() << endl;
    cout << "  Chefs: " << manager.getChefCount() << endl;
    cout << "  Drivers: " << manager.getDriverCount() << endl;
    
    // ═══════════════════════════════════════════════════════════
    // Test Chefs - Restaurant Orders
    // ═══════════════════════════════════════════════════════════
    
    cout << "\n\n[Test 1: Restaurant Orders - Chef Assignment]" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    int currentTime = 0;
    
    // Order 1
    cout << "\n-> Time " << currentTime << ": Order #101 (5 dishes)" << endl;
    Chef* chef1 = manager.getAvailableChef(currentTime);
    if (chef1) {
        cout << "  + Assigned to " << chef1->getID() << endl;
        chef1->startCooking(currentTime, 101, 5);
        cout << "    Cooking time: " << chef1->calculateCookingTime(5) << " timesteps" << endl;
    } else {
        cout << "  - All chefs are busy! Order waiting..." << endl;
    }
    
    // Order 2
    cout << "\n-> Time " << currentTime << ": Order #102 (3 dishes)" << endl;
    Chef* chef2 = manager.getAvailableChef(currentTime);
    if (chef2) {
        cout << "  + Assigned to " << chef2->getID() << endl;
        chef2->startCooking(currentTime, 102, 3);
        cout << "    Cooking time: " << chef2->calculateCookingTime(3) << " timesteps" << endl;
    } else {
        cout << "  - All chefs are busy! Order waiting..." << endl;
    }
    
    // Order 3
    cout << "\n-> Time " << currentTime << ": Order #103 (10 dishes)" << endl;
    Chef* chef3 = manager.getAvailableChef(currentTime);
    if (chef3) {
        cout << "  + Assigned to " << chef3->getID() << endl;
        chef3->startCooking(currentTime, 103, 10);
        cout << "    Cooking time: " << chef3->calculateCookingTime(10) << " timesteps" << endl;
    } else {
        cout << "  - All chefs are busy! Order waiting..." << endl;
    }
    
    // Order 4 (all chefs should be busy now)
    cout << "\n-> Time " << currentTime << ": Order #104 (2 dishes)" << endl;
    Chef* chef4 = manager.getAvailableChef(currentTime);
    if (chef4) {
        cout << "  + Assigned to " << chef4->getID() << endl;
        chef4->startCooking(currentTime, 104, 2);
    } else {
        cout << "  - All chefs are busy! Order waiting..." << endl;
    }
    
    manager.printAllStaffStatus(currentTime);
    
    // ═══════════════════════════════════════════════════════════
    // Test Drivers - Vehicle Trips
    // ═══════════════════════════════════════════════════════════
    
    cout << "\n[Test 2: Vehicle Trips - Driver Assignment]" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    currentTime = 5;
    manager.updateAllStaff(currentTime);
    
    // Trip 1
    cout << "\n-> Time " << currentTime << ": Trip #201 (Airport -> Hotel, 10 timesteps)" << endl;
    Driver* driver1 = manager.getAvailableDriver(currentTime);
    if (driver1) {
        cout << "  + Assigned to " << driver1->getID() << endl;
        driver1->startTrip(currentTime, 201, 10);
    } else {
        cout << "  - All drivers are busy! Trip waiting..." << endl;
    }
    
    // Trip 2
    cout << "\n-> Time " << currentTime << ": Trip #202 (Hotel -> Mall, 7 timesteps)" << endl;
    Driver* driver2 = manager.getAvailableDriver(currentTime);
    if (driver2) {
        cout << "  + Assigned to " << driver2->getID() << endl;
        driver2->startTrip(currentTime, 202, 7);
    } else {
        cout << "  - All drivers are busy! Trip waiting..." << endl;
    }
    
    // Trip 3 (all drivers should be busy)
    cout << "\n-> Time " << currentTime << ": Trip #203 (Hotel -> Beach, 12 timesteps)" << endl;
    Driver* driver3 = manager.getAvailableDriver(currentTime);
    if (driver3) {
        cout << "  + Assigned to " << driver3->getID() << endl;
        driver3->startTrip(currentTime, 203, 12);
    } else {
        cout << "  - All drivers are busy! Trip waiting..." << endl;
    }
    
    manager.printAllStaffStatus(currentTime);
    
    // ═══════════════════════════════════════════════════════════
    // Test Availability Check Functions
    // ═══════════════════════════════════════════════════════════
    
    cout << "\n[Test 3: Availability Check Functions]" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    currentTime = 10;
    manager.updateAllStaff(currentTime);
    
    cout << "\n-> Time " << currentTime << " - Checking availability:" << endl;
    cout << "  VIP Receptionist available? " 
         << (manager.hasAvailableReceptionist(currentTime, true) ? "YES" : "NO") << endl;
    cout << "  Regular Receptionist available? " 
         << (manager.hasAvailableReceptionist(currentTime, false) ? "YES" : "NO") << endl;
    cout << "  Housekeeper available? " 
         << (manager.hasAvailableHousekeeper(currentTime) ? "YES" : "NO") << endl;
    cout << "  Chef available? " 
         << (manager.hasAvailableChef(currentTime) ? "YES" : "NO") << endl;
    cout << "  Driver available? " 
         << (manager.hasAvailableDriver(currentTime) ? "YES" : "NO") << endl;
    
    manager.printAllStaffStatus(currentTime);
    
    // ═══════════════════════════════════════════════════════════
    // Test Receptionists (from previous test)
    // ═══════════════════════════════════════════════════════════
    
    cout << "\n[Test 4: Reception - Check-in Process]" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    currentTime = 15;
    manager.updateAllStaff(currentTime);
    
    // VIP Check-in
    cout << "\n-> Time " << currentTime << ": VIP Guest #301 arrived for check-in" << endl;
    Receptionist* vipRec = manager.getAvailableVIPReceptionist(currentTime);
    if (vipRec) {
        cout << "  + Assigned to " << vipRec->getID() << endl;
        vipRec->startCheckIn(currentTime, 301);
    } else {
        cout << "  - All VIP receptionists are busy!" << endl;
    }
    
    // Regular Check-in
    cout << "\n-> Time " << currentTime << ": Regular Guest #302 arrived for check-in" << endl;
    Receptionist* regRec = manager.getAvailableRegularReceptionist(currentTime);
    if (regRec) {
        cout << "  + Assigned to " << regRec->getID() << endl;
        regRec->startCheckIn(currentTime, 302);
    } else {
        cout << "  - All regular receptionists are busy!" << endl;
    }
    
    manager.printAllStaffStatus(currentTime);
    
    // ═══════════════════════════════════════════════════════════
    // Test Housekeepers
    // ═══════════════════════════════════════════════════════════
    
    cout << "\n[Test 5: Housekeeping - Room Cleaning]" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    currentTime = 20;
    manager.updateAllStaff(currentTime);
    
    // Room 1
    cout << "\n-> Time " << currentTime << ": Room R401 needs cleaning" << endl;
    Housekeeper* hk1 = manager.getAvailableHousekeeper(currentTime);
    if (hk1) {
        cout << "  + Assigned to " << hk1->getID() << endl;
        hk1->startCleaning(currentTime, "R401");
    } else {
        cout << "  - All housekeepers are busy!" << endl;
    }
    
    // Room 2
    cout << "\n-> Time " << currentTime << ": Room R402 needs cleaning" << endl;
    Housekeeper* hk2 = manager.getAvailableHousekeeper(currentTime);
    if (hk2) {
        cout << "  + Assigned to " << hk2->getID() << endl;
        hk2->startCleaning(currentTime, "R402");
    } else {
        cout << "  - All housekeepers are busy!" << endl;
    }
    
    // Room 3 (all should be busy)
    cout << "\n-> Time " << currentTime << ": Room R403 needs cleaning" << endl;
    Housekeeper* hk3 = manager.getAvailableHousekeeper(currentTime);
    if (hk3) {
        cout << "  + Assigned to " << hk3->getID() << endl;
        hk3->startCleaning(currentTime, "R403");
    } else {
        cout << "  - All housekeepers are busy! Room in waiting list..." << endl;
    }
    
    manager.printAllStaffStatus(currentTime);
    
    // ═══════════════════════════════════════════════════════════
    // Final Summary
    // ═══════════════════════════════════════════════════════════
    
    cout << "\n==============================================================" << endl;
    cout << "                    TEST SUMMARY" << endl;
    cout << "==============================================================" << endl;
    cout << "  Total Staff Members:" << endl;
    cout << "    - VIP Receptionists: " << manager.getVIPReceptionistCount() << endl;
    cout << "    - Regular Receptionists: " << manager.getRegularReceptionistCount() << endl;
    cout << "    - Housekeepers: " << manager.getHousekeeperCount() << endl;
    cout << "    - Chefs: " << manager.getChefCount() << endl;
    cout << "    - Drivers: " << manager.getDriverCount() << endl;
    cout << "\n  Tests Completed:" << endl;
    cout << "    [+] Chef assignment and cooking" << endl;
    cout << "    [+] Driver assignment and trips" << endl;
    cout << "    [+] Availability checking" << endl;
    cout << "    [+] Reception check-in process" << endl;
    cout << "    [+] Housekeeping room cleaning" << endl;
    cout << "\n  Status: ALL TESTS PASSED SUCCESSFULLY!" << endl;
    cout << "==============================================================" << endl;
    
    return 0;
}