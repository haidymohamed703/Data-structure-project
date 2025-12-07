#ifndef ORDER_H
#define ORDER_H
#include<bits/stdc++.h>
using namespace std;
enum OrderType{NORMAL,VEGAN,VIP};
class Order {
public:
  int id;
  OrderType type;
  int size;
  int money;
  int RT;
  int GT;
  int ST;
  int FT;
  bool assigned = false;

  Order(int _id, OrderType _t, int _size, int _money, int _RT);

  double getPriority(int currentTime, double alpha=1, double beta=1) const;

};
#endif
