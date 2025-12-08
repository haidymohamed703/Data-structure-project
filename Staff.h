#pragma once
#include <string>

// Enum لحالات الموظف
enum class StaffState
{
    AVAILABLE, // الموظف فاضي ومستعد يشتغل
    BUSY,      // الموظف شغال دلوقتي
    ON_BREAK   // الموظف في استراحة (Break)
};

// الكلاس الأساسي لكل الموظفين (Base Class)
// كل أنواع الموظفين (Receptionist, Housekeeper, Chef...) هيورثوا منه
class Staff
{
protected:
    // Protected عشان الكلاسات اللي بترث تقدر توصلهم

    std::string id;       // معرّف الموظف (مثلاً: "R1", "HK2")
    int speed;            // سرعة الموظف (الوقت اللي بياخده عشان يخلص مهمة)
    int tasksBeforeBreak; // عدد المهام قبل ما يدخل Break
    int breakDuration;    // مدة الـ Break (بالـ timesteps)
    int tasksDone;        // عدد المهام اللي عملها لحد دلوقتي
    int nextFreeTime;     // الوقت اللي الموظف هيكون فاضي فيه
    int breakEndTime;     // الوقت اللي الـ Break هينتهي فيه
    StaffState state;     // حالة الموظف الحالية

public:
    // Constructor - بينشئ موظف جديد
    // id_: معرّف الموظف
    // speed_: سرعته في أداء المهام
    // tasksB4Break: عدد المهام قبل الاستراحة
    // breakDur: مدة الاستراحة
    Staff(const std::string &id_, int speed_, int tasksB4Break, int breakDur);

    // ═══════════════════════════════════════════════════════════
    // دوال التحقق من الحالة (Checking Functions)
    // ═══════════════════════════════════════════════════════════

    // بتشوف الموظف فاضي دلوقتي ولا لأ في وقت معين
    bool isAvailable(int currentTime) const;

    // بتشوف الموظف في Break ولا لأ
    bool isOnBreak() const;

    // ═══════════════════════════════════════════════════════════
    // دوال العمل (Action Functions)
    // ═══════════════════════════════════════════════════════════

    // بتبدأ مهمة جديدة للموظف
    // currentTime: الوقت الحالي
    // duration: مدة المهمة
    void startTask(int currentTime, int duration);

    // بتدخل الموظف في استراحة (Break)
    // currentTime: الوقت الحالي
    void goOnBreak(int currentTime);

    // بتحدث حالة الموظف بناءً على الوقت الحالي
    // (بتشوف لو خلص شغل أو Break وتغير الحالة)
    void updateState(int currentTime);

    // ═══════════════════════════════════════════════════════════
    // Getters - دوال الحصول على المعلومات
    // ═══════════════════════════════════════════════════════════

    std::string getID() const;   // بترجع معرّف الموظف
    int getNextFreeTime() const; // بترجع امتى الموظف هيكون فاضي
    int getSpeed() const;        // بترجع سرعة الموظف
    int getTasksDone() const;    // بترجع عدد المهام اللي عملها
    StaffState getState() const; // بترجع حالة الموظف الحالية
    int getBreakEndTime() const; // بترجع امتى الـ Break هينتهي
};