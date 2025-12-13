#pragma once
#include "Staff.h"
#include <string>

// كلاس السائق (Driver)
// بيورث من Staff ويضيف وظيفة قيادة الرحلات
class Driver : public Staff {
public:
    // ═══════════════════════════════════════════════════════════
    // Constructor - إنشاء سائق جديد
    // ═══════════════════════════════════════════════════════════
    // id_: معرّف الموظف (مثلاً "DR1", "DR2")
    // speed: سرعة القيادة (الوقت الثابت لكل رحلة، أو يتحسب حسب المسافة)
    // tasksBeforeBreak: عدد الرحلات قبل البريك
    // breakDur: مدة البريك
    Driver(const std::string &id_, 
           int speed, 
           int tasksBeforeBreak, 
           int breakDur)
        : Staff(id_, speed, tasksBeforeBreak, breakDur)
    {
        // كل الـ initialization اتعمل في Staff
    }

    // ═══════════════════════════════════════════════════════════
    // دوال الوظيفة الأساسية
    // ═══════════════════════════════════════════════════════════
    
    // بتحسب الوقت اللازم لرحلة
    // tripDuration: مدة الرحلة (ممكن تتحسب حسب المسافة)
    // 
    // ملحوظة: في الحالة البسيطة، ممكن نستخدم speed كـ fixed duration
    // أو Person 5 يحسبها بناءً على المسافة
    int calculateTripDuration(int tripDuration) const {
        // في الحالة البسيطة: نستخدم الـ tripDuration اللي جاي
        // أو ممكن نستخدم speed لو كل الرحلات نفس المدة
        return tripDuration;
    }
    
    // بتبدأ رحلة جديدة
    // currentTime: الوقت الحالي
    // tripID: رقم الرحلة
    // tripDuration: مدة الرحلة
    void startTrip(int currentTime, int tripID, int tripDuration) {
        // نحسب الوقت اللازم
        int duration = calculateTripDuration(tripDuration);
        
        // نبدأ المهمة (من Staff)
        startTask(currentTime, duration);
        
        // ممكن نطبع للـ debugging:
        // std::cout << "Driver " << id << " started trip " 
        //           << tripID << " at time " << currentTime 
        //           << " (will finish at " << getNextFreeTime() << ")" << std::endl;
    }
    
    // دالة بديلة: لو عايزين نستخدم الـ speed مباشرة
    void startTripWithFixedDuration(int currentTime, int tripID) {
        startTask(currentTime, speed);
    }
};