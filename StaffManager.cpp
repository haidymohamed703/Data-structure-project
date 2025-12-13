#include "StaffManager.h"

// ═══════════════════════════════════════════════════════════
// Constructor & Destructor
// ═══════════════════════════════════════════════════════════

StaffManager::StaffManager() {
    // مفيش حاجة محتاجة initialization
}

StaffManager::~StaffManager() {
    // نعمل cleanup لكل الـ pointers
    
    for (auto r : vipReceptionists) delete r;
    for (auto r : regularReceptionists) delete r;
    for (auto h : housekeepers) delete h;
    for (auto c : chefs) delete c;           // ✅ جديد
    for (auto d : drivers) delete d;         // ✅ جديد
}

// ═══════════════════════════════════════════════════════════
// إضافة موظفين جدد
// ═══════════════════════════════════════════════════════════

void StaffManager::addVIPReceptionist(const std::string &id, int speed, 
                                      int tasksBeforeBreak, int breakDur) {
    Receptionist* newReceptionist = new Receptionist(id, speed, tasksBeforeBreak, breakDur, true);
    vipReceptionists.push_back(newReceptionist);
    std::cout << "تم إضافة VIP Receptionist: " << id << std::endl;
}

void StaffManager::addRegularReceptionist(const std::string &id, int speed, 
                                         int tasksBeforeBreak, int breakDur) {
    Receptionist* newReceptionist = new Receptionist(id, speed, tasksBeforeBreak, breakDur, false);
    regularReceptionists.push_back(newReceptionist);
    std::cout << "تم إضافة Regular Receptionist: " << id << std::endl;
}

void StaffManager::addHousekeeper(const std::string &id, int speed, 
                                  int tasksBeforeBreak, int breakDur) {
    Housekeeper* newHousekeeper = new Housekeeper(id, speed, tasksBeforeBreak, breakDur);
    housekeepers.push_back(newHousekeeper);
    std::cout << "تم إضافة Housekeeper: " << id << std::endl;
}

// ✅ إضافة Chef
void StaffManager::addChef(const std::string &id, int speed, 
                          int tasksBeforeBreak, int breakDur) {
    Chef* newChef = new Chef(id, speed, tasksBeforeBreak, breakDur);
    chefs.push_back(newChef);
    std::cout << "تم إضافة Chef: " << id << std::endl;
}

// ✅ إضافة Driver
void StaffManager::addDriver(const std::string &id, int speed, 
                            int tasksBeforeBreak, int breakDur) {
    Driver* newDriver = new Driver(id, speed, tasksBeforeBreak, breakDur);
    drivers.push_back(newDriver);
    std::cout << "تم إضافة Driver: " << id << std::endl;
}

// ═══════════════════════════════════════════════════════════
// إيجاد موظف فاضي
// ═══════════════════════════════════════════════════════════

Receptionist* StaffManager::getAvailableVIPReceptionist(int currentTime) {
    for (auto receptionist : vipReceptionists) {
        if (receptionist->isAvailable(currentTime)) {
            return receptionist;
        }
    }
    return nullptr;
}

Receptionist* StaffManager::getAvailableRegularReceptionist(int currentTime) {
    for (auto receptionist : regularReceptionists) {
        if (receptionist->isAvailable(currentTime)) {
            return receptionist;
        }
    }
    return nullptr;
}

Housekeeper* StaffManager::getAvailableHousekeeper(int currentTime) {
    for (auto housekeeper : housekeepers) {
        if (housekeeper->isAvailable(currentTime)) {
            return housekeeper;
        }
    }
    return nullptr;
}

// ✅ إيجاد Chef فاضي
Chef* StaffManager::getAvailableChef(int currentTime) {
    for (auto chef : chefs) {
        if (chef->isAvailable(currentTime)) {
            return chef;
        }
    }
    return nullptr;
}

// ✅ إيجاد Driver فاضي
Driver* StaffManager::getAvailableDriver(int currentTime) {
    for (auto driver : drivers) {
        if (driver->isAvailable(currentTime)) {
            return driver;
        }
    }
    return nullptr;
}

// ═══════════════════════════════════════════════════════════
// تحديث حالة كل الموظفين
// ═══════════════════════════════════════════════════════════

void StaffManager::updateAllStaff(int currentTime) {
    for (auto r : vipReceptionists) r->updateState(currentTime);
    for (auto r : regularReceptionists) r->updateState(currentTime);
    for (auto h : housekeepers) h->updateState(currentTime);
    for (auto c : chefs) c->updateState(currentTime);        // ✅ جديد
    for (auto d : drivers) d->updateState(currentTime);      // ✅ جديد
}

// ═══════════════════════════════════════════════════════════
// معلومات عن الموظفين
// ═══════════════════════════════════════════════════════════

int StaffManager::getVIPReceptionistCount() const {
    return vipReceptionists.size();
}

int StaffManager::getRegularReceptionistCount() const {
    return regularReceptionists.size();
}

int StaffManager::getHousekeeperCount() const {
    return housekeepers.size();
}

// ✅ عدد الشيفات
int StaffManager::getChefCount() const {
    return chefs.size();
}

// ✅ عدد السواقين
int StaffManager::getDriverCount() const {
    return drivers.size();
}

// ═══════════════════════════════════════════════════════════
// دوال التحقق من التوفر
// ═══════════════════════════════════════════════════════════

// ✅ بتشوف في receptionist فاضي ولا لأ
bool StaffManager::hasAvailableReceptionist(int currentTime, bool isVIP) const {
    if (isVIP) {
        for (const auto r : vipReceptionists) {
            if (r->isAvailable(currentTime)) return true;
        }
    } else {
        for (const auto r : regularReceptionists) {
            if (r->isAvailable(currentTime)) return true;
        }
    }
    return false;
}

// ✅ بتشوف في housekeeper فاضي ولا لأ
bool StaffManager::hasAvailableHousekeeper(int currentTime) const {
    for (const auto h : housekeepers) {
        if (h->isAvailable(currentTime)) return true;
    }
    return false;
}

// ✅ بتشوف في chef فاضي ولا لأ
bool StaffManager::hasAvailableChef(int currentTime) const {
    for (const auto c : chefs) {
        if (c->isAvailable(currentTime)) return true;
    }
    return false;
}

// ✅ بتشوف في driver فاضي ولا لأ
bool StaffManager::hasAvailableDriver(int currentTime) const {
    for (const auto d : drivers) {
        if (d->isAvailable(currentTime)) return true;
    }
    return false;
}

// ═══════════════════════════════════════════════════════════
// طباعة حالة كل الموظفين
// ═══════════════════════════════════════════════════════════

void StaffManager::printAllStaffStatus(int currentTime) const {
    std::cout << "\n═══════════════════════════════════════════════" << std::endl;
    std::cout << "        حالة الموظفين في الوقت " << currentTime << std::endl;
    std::cout << "═══════════════════════════════════════════════" << std::endl;
    
    // VIP Receptionists
    std::cout << "\n[VIP Receptionists]" << std::endl;
    for (const auto r : vipReceptionists) {
        std::cout << "  " << r->getID() << ": ";
        if (r->isAvailable(currentTime)) std::cout << "AVAILABLE";
        else if (r->isOnBreak()) std::cout << "ON BREAK (until " << r->getBreakEndTime() << ")";
        else std::cout << "BUSY (free at " << r->getNextFreeTime() << ")";
        std::cout << " | Tasks: " << r->getTasksDone() << std::endl;
    }
    
    // Regular Receptionists
    std::cout << "\n[Regular Receptionists]" << std::endl;
    for (const auto r : regularReceptionists) {
        std::cout << "  " << r->getID() << ": ";
        if (r->isAvailable(currentTime)) std::cout << "AVAILABLE";
        else if (r->isOnBreak()) std::cout << "ON BREAK (until " << r->getBreakEndTime() << ")";
        else std::cout << "BUSY (free at " << r->getNextFreeTime() << ")";
        std::cout << " | Tasks: " << r->getTasksDone() << std::endl;
    }
    
    // Housekeepers
    std::cout << "\n[Housekeepers]" << std::endl;
    for (const auto h : housekeepers) {
        std::cout << "  " << h->getID() << ": ";
        if (h->isAvailable(currentTime)) std::cout << "AVAILABLE";
        else if (h->isOnBreak()) std::cout << "ON BREAK (until " << h->getBreakEndTime() << ")";
        else std::cout << "BUSY (free at " << h->getNextFreeTime() << ")";
        std::cout << " | Tasks: " << h->getTasksDone() << std::endl;
    }
    
    // ✅ Chefs
    std::cout << "\n[Chefs]" << std::endl;
    for (const auto c : chefs) {
        std::cout << "  " << c->getID() << ": ";
        if (c->isAvailable(currentTime)) std::cout << "AVAILABLE";
        else if (c->isOnBreak()) std::cout << "ON BREAK (until " << c->getBreakEndTime() << ")";
        else std::cout << "BUSY (free at " << c->getNextFreeTime() << ")";
        std::cout << " | Tasks: " << c->getTasksDone() << std::endl;
    }
    
    // ✅ Drivers
    std::cout << "\n[Drivers]" << std::endl;
    for (const auto d : drivers) {
        std::cout << "  " << d->getID() << ": ";
        if (d->isAvailable(currentTime)) std::cout << "AVAILABLE";
        else if (d->isOnBreak()) std::cout << "ON BREAK (until " << d->getBreakEndTime() << ")";
        else std::cout << "BUSY (free at " << d->getNextFreeTime() << ")";
        std::cout << " | Tasks: " << d->getTasksDone() << std::endl;
    }
    
    std::cout << "═══════════════════════════════════════════════\n" << std::endl;
}