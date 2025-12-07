#ifndef RESTAURANT_SYSTEM_H
#define RESTAURANT_SYSTEM_H
#include <bits/stdc++.h>
#include "Order.h"
#include "Chef.h"
using namespace std;
class RestaurantSystem{
public:
    queue<Order*> normalQ;
    queue<Order*> veganQ;
    vector<Order*> vipList;

    vector<Chef*> vipChefs;
    vector<Chef*> veganChefs;
    vector<Chef*> normalChefs;

    void addOrder(Order*);
    void assignOrder(int currentTime);
    void updateChefs();

private:
    void assignVIP(int currentTime);
    void assignVegan(int currentTime);
    void assignNormal(int currentTime);
    
    bool hasFreeChef(vector<Chef*>&list);
    Chef* getAvailableChef(vector<Chef*>&list);
    void assignOrderToChef(Order*ord,Chef*chef,int currentTime);
};
#endif