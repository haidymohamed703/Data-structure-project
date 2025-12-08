#pragma once
#include "Staff.h"
#include <string>

// كلاس عامل التنضيف (Housekeeper)
// بيورث من Staff ويضيف وظيفة تنضيف الغرف

class Housekeeper : public Staff
{
public:
    // ═══════════════════════════════════════════════════════════
    // Constructor - إنشاء housekeeper جديد
    // ═══════════════════════════════════════════════════════════
    // id_: معرّف الموظف (مثلاً "HK1", "HK2")
    // speed: سرعة التنضيف (الوقت اللي بياخده عشان ينضف غرفة)
    // tasksBeforeBreak: عدد الغرف اللي ينضفها قبل البريك
    // breakDur: مدة البريك

    Housekeeper(const std::string &id_,
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

    // بتحسب الوقت اللازم لتنضيف غرفة
    // (في الحالة البسيطة، هو نفس الـ speed)

    int calculateCleaningDuration() const
    {
        return speed; // speed موجود في Staff كـ protected member
    }

    // بتبدأ عملية تنضيف غرفة
    // currentTime: الوقت الحالي
    // roomID: رقم الغرفة اللي هننضفها

    void startCleaning(int currentTime, const std::string &roomID)
    {
        // نحسب الوقت اللازم
        int duration = calculateCleaningDuration();

        // نبدأ المهمة (من Staff)
        startTask(currentTime, duration);

        // ممكن نطبع للـ debugging:
        // std::cout << "Housekeeper " << id << " started cleaning room "
        //           << roomID << " at time " << currentTime
        //           << " (will finish at " << getNextFreeTime() << ")" << std::endl;
    }
};