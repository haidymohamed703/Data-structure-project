#pragma once
#include "Receptionist.h"
#include "Housekeeper.h"
#include "Chef.h"        // ✅ جديد
#include "Driver.h"      // ✅ جديد
#include <vector>
#include <iostream>

// كلاس لإدارة كل الموظفين في الفندق
// بيخزن lists من كل نوع موظف ويساعد في إيجاد موظف فاضي
class StaffManager {
private:
    // Lists للموظفين
    std::vector<Receptionist*> vipReceptionists;      // موظفي استقبال VIP
    std::vector<Receptionist*> regularReceptionists;  // موظفي استقبال عادي
    std::vector<Housekeeper*> housekeepers;           // عمال التنضيف
    std::vector<Chef*> chefs;                         // ✅ الشيفات
    std::vector<Driver*> drivers;                     // ✅ السواقين

public:
    // ═══════════════════════════════════════════════════════════
    // Constructor & Destructor
    // ═══════════════════════════════════════════════════════════
    
    StaffManager();
    ~StaffManager();  // عشان نعمل cleanup للـ pointers
    
    // ═══════════════════════════════════════════════════════════
    // إضافة موظفين جدد
    // ═══════════════════════════════════════════════════════════
    
    // إضافة VIP receptionist
    void addVIPReceptionist(const std::string &id, int speed, 
                           int tasksBeforeBreak, int breakDur);
    
    // إضافة Regular receptionist
    void addRegularReceptionist(const std::string &id, int speed, 
                               int tasksBeforeBreak, int breakDur);
    
    // إضافة Housekeeper
    void addHousekeeper(const std::string &id, int speed, 
                       int tasksBeforeBreak, int breakDur);
    
    // ✅ إضافة Chef
    void addChef(const std::string &id, int speed, 
                int tasksBeforeBreak, int breakDur);
    
    // ✅ إضافة Driver
    void addDriver(const std::string &id, int speed, 
                  int tasksBeforeBreak, int breakDur);
    
    // ═══════════════════════════════════════════════════════════
    // إيجاد موظف فاضي
    // ═══════════════════════════════════════════════════════════
    
    // إيجاد أول VIP receptionist فاضي
    Receptionist* getAvailableVIPReceptionist(int currentTime);
    
    // إيجاد أول Regular receptionist فاضي
    Receptionist* getAvailableRegularReceptionist(int currentTime);
    
    // إيجاد أول Housekeeper فاضي
    Housekeeper* getAvailableHousekeeper(int currentTime);
    
    // ✅ إيجاد أول Chef فاضي
    Chef* getAvailableChef(int currentTime);
    
    // ✅ إيجاد أول Driver فاضي
    Driver* getAvailableDriver(int currentTime);
    
    // ═══════════════════════════════════════════════════════════
    // تحديث حالة كل الموظفين
    // ═══════════════════════════════════════════════════════════
    
    void updateAllStaff(int currentTime);
    
    // ═══════════════════════════════════════════════════════════
    // معلومات عن الموظفين
    // ═══════════════════════════════════════════════════════════
    
    int getVIPReceptionistCount() const;
    int getRegularReceptionistCount() const;
    int getHousekeeperCount() const;
    int getChefCount() const;        // ✅ جديد
    int getDriverCount() const;      // ✅ جديد
    
    // ═══════════════════════════════════════════════════════════
    // دوال للتحقق من التوفر (مفيدة للـ Integration)
    // ═══════════════════════════════════════════════════════════
    
    // ✅ بتشوف في receptionist فاضي ولا لأ
    bool hasAvailableReceptionist(int currentTime, bool isVIP) const;
    
    // ✅ بتشوف في housekeeper فاضي ولا لأ
    bool hasAvailableHousekeeper(int currentTime) const;
    
    // ✅ بتشوف في chef فاضي ولا لأ
    bool hasAvailableChef(int currentTime) const;
    
    // ✅ بتشوف في driver فاضي ولا لأ
    bool hasAvailableDriver(int currentTime) const;
    
    // طباعة حالة كل الموظفين (للـ debugging)
    void printAllStaffStatus(int currentTime) const;
};