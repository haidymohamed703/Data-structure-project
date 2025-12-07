#include "Order.h"
Order::Order(int _id,OrderType _t,int _size,int _money,int _RT)
     :id(_id), type(_t),size(_size),money(_money),RT(_RT){}
double Order::getPriority(int currentTime,double alpha,double beta) const {
    return (money * alpha) / (size * beta * (currentTime - RT + 1));
}
