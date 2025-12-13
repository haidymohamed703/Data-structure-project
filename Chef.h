// =================== Chef البسيط ===================
#ifndef CHEF2_H
#define CHEF2_H
#include <bits/stdc++.h>
#include "Order.h"
using namespace std;

enum ChefType { Chef_NORMAL, Chef_VEGAN, Chef_VIP };

class Chef2 {  // غيرنا الاسم عشان مفيش conflict
public:
    int id;
    ChefType type;
    int speed;
    bool busy = false;
    int remainingTime = 0;
    Order* currentOrder = nullptr;

    Chef2(int _id, ChefType _t, int _speed);
};

#endif

// =================== Chef المتقدم (وارث من Staff) ===================
#pragma once
#include "Staff.h"
#include <string>
#include <cmath>  // لاستخدام ceil()

// كلاس الشيف (Chef)
// بيورث من Staff ويضيف وظيفة طبخ الطلبات
class Chef : public Staff {
public:
    // Constructor - إنشاء شيف جديد
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

    // بتحسب الوقت اللازم لطبخ طلب
    int calculateCookingTime(int orderSize) const {
        return std::ceil(static_cast<double>(orderSize) / speed);
    }
    
    // بتبدأ عملية طبخ طلب
    void startCooking(int currentTime, int orderID, int orderSize) {
        int duration = calculateCookingTime(orderSize);
        startTask(currentTime, duration);
    }
};
