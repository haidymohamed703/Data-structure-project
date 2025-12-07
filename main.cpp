#include <bits/stdc++.h>
#include "RestaurantSystem.h"
using namespace std;

int main() {
    RestaurantSystem R;
    R.vipChefs.push_back(new Chef(1,Chef_VIP,3));
    R.normalChefs.push_back(new Chef(2,Chef_NORMAL,2));
    R.veganChefs.push_back(new Chef(3,Chef_VEGAN,1));
   
    R.addOrder(new Order(100,VIP,5,450,1));
    R.addOrder(new Order(101,NORMAL,3,600,1));
    R.addOrder(new Order(102,VEGAN,6,200,1));
    R.addOrder(new Order(103,VIP,2,150,1));
    R.addOrder(new Order(104,NORMAL,4,700,1));
    R.addOrder(new Order(105,VEGAN,3,300,1));
    R.addOrder(new Order(106,NORMAL,7,800,1));

    int time = 1;

    while (true) {
        cout << "\n--- Time = " << time << "--- \n";

        R.updateChefs();
        R.assignOrder(time);

        bool stillOrders =
            !R.normalQ.empty() ||
            !R.veganQ.empty()  ||
            !R.vipList.empty();

        bool chefsBusy = false;
        for (auto c : R.vipChefs) if (c->busy) chefsBusy = true;
        for (auto c : R.normalChefs) if (c->busy) chefsBusy = true;
        for (auto c : R.veganChefs) if (c->busy) chefsBusy = true;

        if (!stillOrders && !chefsBusy)
            break;

        time++;
   }
    return 0;
}