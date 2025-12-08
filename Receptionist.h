#pragma once
#include "Staff.h"
#include <string>

// كلاس موظف الاستقبال (Receptionist)
// بيورث من Staff ويضيف وظيفة الـ Check-in

class Receptionist : public Staff
{
private:
    bool isVIP; // هل ده receptionist للـ VIP ولا Regular؟

public:
    // ═══════════════════════════════════════════════════════════
    // Constructor - إنشاء receptionist جديد
    // ═══════════════════════════════════════════════════════════
    // id_: معرّف الموظف (مثلاً "VIP_R1" أو "REG_R1")
    // speed: سرعة عمل الـ Check-in (الوقت اللي بياخده)
    // tasksBeforeBreak: عدد الـ Check-ins قبل البريك
    // breakDur: مدة البريك
    // vip: هل ده VIP receptionist؟ (default = false)

    Receptionist(const std::string &id_,
                 int speed,
                 int tasksBeforeBreak,
                 int breakDur,
                 bool vip = false)
        : Staff(id_, speed, tasksBeforeBreak, breakDur), // بنبعت كل حاجة للـ Staff
          isVIP(vip)
    {
        // كل الـ initialization اتعمل في Staff
    }

    // ═══════════════════════════════════════════════════════════
    // دوال الوظيفة الأساسية
    // ═══════════════════════════════════════════════════════════

    // بتحسب الوقت اللازم لعمل Check-in
    // (في الحالة البسيطة، هو نفس الـ speed)

    int calculateCheckInTime() const
    {
        return speed; // speed موجود في Staff كـ protected member
    }

    // بتبدأ عملية Check-in لحجز معين
    // currentTime: الوقت الحالي
    // reservationID: رقم الحجز اللي بنعمله Check-in

    void startCheckIn(int currentTime, int reservationID)
    {
        // نحسب الوقت اللازم
        int duration = calculateCheckInTime();

        // نبدأ المهمة (من Staff)
        startTask(currentTime, duration);

        // ممكن نطبع للـ debugging:
        // std::cout << "Receptionist " << id << " started check-in for reservation "
        //           << reservationID << " at time " << currentTime << std::endl;
    }

    // بترجع هل ده VIP receptionist ولا لأ
    bool getIsVIP() const
    {
        return isVIP;
    }
};