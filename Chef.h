#pragma once
#include "Staff.h"
#include <string>
#include <cmath>  // لاستخدام ceil()

// كلاس الشيف (Chef)
// بيورث من Staff ويضيف وظيفة طبخ الطلبات
class Chef : public Staff {
public:
    // ═══════════════════════════════════════════════════════════
    // Constructor - إنشاء شيف جديد
    // ═══════════════════════════════════════════════════════════
    // id_: معرّف الموظف (مثلاً "CH1", "CH2")
    // speed: سرعة الطبخ (عدد الأطباق في الـ timestep الواحد)
    // tasksBeforeBreak: عدد الطلبات اللي يطبخها قبل البريك
    // breakDur: مدة البريك
    Chef(const std::string &id_, 
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
    
    // بتحسب الوقت اللازم لطبخ طلب
    // orderSize: عدد الأطباق في الطلب
    // المعادلة: ceil(orderSize / speed)
    int calculateCookingTime(int orderSize) const {
        // نستخدم ceil عشان نطلّع رقم صحيح للأعلى
        // مثال: لو orderSize = 5 و speed = 20
        // الوقت = ceil(5/20) = ceil(0.25) = 1 timestep
        return std::ceil(static_cast<double>(orderSize) / speed);
    }
    
    // بتبدأ عملية طبخ طلب
    // currentTime: الوقت الحالي
    // orderID: رقم الطلب اللي هيطبخه
    // orderSize: حجم الطلب (عدد الأطباق)
    void startCooking(int currentTime, int orderID, int orderSize) {
        // نحسب الوقت اللازم
        int duration = calculateCookingTime(orderSize);
        
        // نبدأ المهمة (من Staff)
        startTask(currentTime, duration);
        
        // ممكن نطبع للـ debugging:
        // std::cout << "Chef " << id << " started cooking order " 
        //           << orderID << " (size: " << orderSize << ")"
        //           << " at time " << currentTime 
        //           << " (will finish at " << getNextFreeTime() << ")" << std::endl;
    }
};