#ifndef CHEF_H
#define CHEF_H
#include <bits/stdc++.h>
#include "Order.h"
using namespace std;
enum ChefType { Chef_NORMAL,Chef_VEGAN,Chef_VIP};
class Chef{
public:
    int id;
    ChefType type;
    int speed;
    bool busy = false;
    int remainingTime = 0;
    Order* currentOrder = nullptr;

    Chef (int _id,ChefType _t,int _speed);
};
#endif