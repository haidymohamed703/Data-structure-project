#include "Staff.h"

// ═══════════════════════════════════════════════════════════
// Constructor - إنشاء موظف جديد
// ═══════════════════════════════════════════════════════════
Staff::Staff(const std::string &id_, int speed_, int tasksB4Break, int breakDur)
    : id(id_),                        // معرّف الموظف
      speed(speed_),                  // سرعته
      tasksBeforeBreak(tasksB4Break), // عدد المهام قبل البريك
      breakDuration(breakDur),        // مدة البريك
      tasksDone(0),                   // في البداية مش عامل أي حاجة
      nextFreeTime(0),                // فاضي من الوقت 0
      breakEndTime(0),                // مفيش بريك في البداية
      state(StaffState::AVAILABLE)    // الموظف فاضي في البداية
{
    // مفيش حاجة تانية محتاجة initialization
}

// ═══════════════════════════════════════════════════════════
// Getters - دوال الحصول على المعلومات
// ═══════════════════════════════════════════════════════════

std::string Staff::getID() const
{
    return id;
}

StaffState Staff::getState() const
{
    return state;
}

int Staff::getSpeed() const
{
    return speed;
}

int Staff::getTasksDone() const
{
    return tasksDone;
}

int Staff::getBreakEndTime() const
{
    return breakEndTime;
}

int Staff::getNextFreeTime() const
{
    return nextFreeTime;
}

bool Staff::isOnBreak() const
{
    return state == StaffState::ON_BREAK;
}

// ═══════════════════════════════════════════════════════════
// isAvailable - بتشوف الموظف فاضي ولا لأ
// ═══════════════════════════════════════════════════════════
bool Staff::isAvailable(int currentTime) const
{

    // لو الموظف في Break
    if (state == StaffState::ON_BREAK)
    {
        // نشوف البريك خلص ولا لسه
        return currentTime >= breakEndTime;
    }

    // لو الموظف شغال (BUSY)
    if (state == StaffState::BUSY)
    {
        // نشوف الشغل خلص ولا لسه
        return currentTime >= nextFreeTime;
    }

    // لو الموظف AVAILABLE
    // نتأكد إن الوقت الحالي >= الوقت اللي هيكون فاضي فيه
    return state == StaffState::AVAILABLE && currentTime >= nextFreeTime;
}

// ═══════════════════════════════════════════════════════════
// startTask - بتبدأ مهمة جديدة
// ═══════════════════════════════════════════════════════════
void Staff::startTask(int currentTime, int duration)
{

    // الموظف بقى شغال (BUSY)
    state = StaffState::BUSY;

    // الموظف هيكون فاضي بعد المدة دي
    nextFreeTime = currentTime + duration;

    // نزوّد عداد المهام
    tasksDone++;

    // ملحوظة: updateState() هي اللي هتشوف لو محتاج Break بعد ما يخلص
}

// ═══════════════════════════════════════════════════════════
// goOnBreak - بتدخل الموظف في استراحة
// ═══════════════════════════════════════════════════════════
void Staff::goOnBreak(int currentTime)
{

    // الموظف بقى في Break
    state = StaffState::ON_BREAK;

    // البريك هينتهي بعد breakDuration
    breakEndTime = currentTime + breakDuration;

    // الموظف هيكون فاضي بعد ما البريك يخلص
    nextFreeTime = breakEndTime;

    // نصفّر عداد المهام (بعد البريك نبدأ من جديد)
    tasksDone = 0;
}

// ═══════════════════════════════════════════════════════════
// updateState - بتحدث حالة الموظف بناءً على الوقت
// ═══════════════════════════════════════════════════════════
void Staff::updateState(int currentTime)
{

    // لو الموظف في Break
    if (state == StaffState::ON_BREAK)
    {
        // نشوف البريك خلص ولا لسه
        if (currentTime >= breakEndTime)
        {
            // البريك خلص، الموظف بقى فاضي
            state = StaffState::AVAILABLE;
        }
        return; // خلصنا، نخرج من الدالة
    }

    // لو الموظف شغال (BUSY)
    if (state == StaffState::BUSY)
    {
        // نشوف الشغل خلص ولا لسه
        if (currentTime >= nextFreeTime)
        {

            // الشغل خلص! نشوف محتاج Break ولا لأ
            if (tasksDone >= tasksBeforeBreak)
            {
                // محتاج Break! ندخله فيه
                goOnBreak(currentTime);
            }
            else
            {
                // مش محتاج Break، يبقى فاضي عادي
                state = StaffState::AVAILABLE;
            }
        }
    }

    // لو AVAILABLE مفيش حاجة نعملها
}