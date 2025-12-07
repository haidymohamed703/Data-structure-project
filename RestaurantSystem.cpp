#include "RestaurantSystem.h"
void RestaurantSystem::addOrder(Order*o){
    if (o->type==VIP) vipList.push_back(o);
    else if (o->type==VEGAN) veganQ.push(o);
    else  normalQ.push(o);
}
void RestaurantSystem::assignOrder(int currentTime) {
    assignVIP(currentTime);
    assignVegan(currentTime);
    assignNormal(currentTime);
}
void RestaurantSystem::assignVIP(int currentTime) {
    if (vipList.empty()) return;

    sort(vipList.begin(),vipList.end(),[&](Order*a,Order*b){
        return a->getPriority(currentTime) > b->getPriority(currentTime);
    });

    for(int t = currentTime; !vipList.empty(); t++) {

    for(Order* ord : vipList) {
        if(ord->assigned) continue;

        Chef* chef=nullptr;
        if(hasFreeChef(vipChefs))
           chef= getAvailableChef(vipChefs);
        else if (hasFreeChef(normalChefs))
           chef= getAvailableChef(normalChefs);
        else if (hasFreeChef(veganChefs))
           chef= getAvailableChef(veganChefs);

        if (chef)
            assignOrderToChef(ord,chef,currentTime);
    }
    vipList.erase(
        remove_if(vipList.begin(),vipList.end(),[](Order*o){return o->assigned; }),
        vipList.end()
    );
}
}
void RestaurantSystem::assignVegan(int currentTime){
    while (!veganQ.empty()&& hasFreeChef(veganChefs)){
        Order*ord=veganQ.front();
        veganQ.pop();
        Chef*chef=getAvailableChef(veganChefs);
        assignOrderToChef(ord,chef,currentTime);
    }
}
void RestaurantSystem::assignNormal(int currentTime){
    queue<Order*> remaining;
    while(!normalQ.empty()) {
        Order*ord=normalQ.front();
        normalQ.pop();

        Chef*chef=nullptr;
        if (hasFreeChef(normalChefs)) chef=getAvailableChef(normalChefs);
        else if(hasFreeChef(vipChefs)) chef =getAvailableChef(vipChefs);

        if (chef) assignOrderToChef(ord,chef,currentTime);
        else remaining.push(ord);
    }
    normalQ = remaining;
}
bool RestaurantSystem::hasFreeChef(vector<Chef*>&list){
    for (auto c : list)
        if(!c->busy) return true;
    return false;
}
Chef*RestaurantSystem::getAvailableChef(vector<Chef*>&list){
    for(auto c : list)
       if(!c->busy) return c;
    return nullptr;
}
void RestaurantSystem::updateChefs() {
    for (auto& c : vipChefs) {
        if (c->busy) {
            c->remainingTime--;
            if (c->remainingTime <= 0) {
                c->busy = false;
                c->currentOrder = nullptr;
            } } }

    for (auto& c : normalChefs) {
        if (c->busy) {
            c->remainingTime--;
            if (c->remainingTime <= 0) {
                c->busy = false;
                c->currentOrder = nullptr;
          }} }

    for (auto& c : veganChefs) {
        if (c->busy) {
            c->remainingTime--;
            if (c->remainingTime <= 0) {
                c->busy = false;
                c->currentOrder = nullptr;
            } } }
}
void RestaurantSystem:: assignOrderToChef(Order*ord,Chef*chef,int currentTime){
    ord->assigned=true;
    ord->GT = currentTime;
    ord->ST = (ord->size + chef->speed -1)/chef->speed;
    ord->FT = ord->GT + ord->ST;

    chef->busy=true;
    chef->remainingTime= ord->ST;
    chef->currentOrder = ord;
    cout <<" Assigned order " << ord->id 
         <<" to chef " << chef->id
         << " ST= " << ord->ST
         << " FT= " << ord->FT << endl;

}