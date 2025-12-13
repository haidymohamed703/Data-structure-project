#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>
using namespace std;

//Reservation Class
class Reservation {
private:
    int ReservationID;         
    string CustomerType;    
    int ArrivalTime;          
    int Nights;                  
    string RequestedRoomType;
    string AssignedRoomID;      
    int CheckInTime;            
    int CheckOutTime;            
    int WaitingTime;             
    bool IsCancelled;           
    bool IsUpgraded;
    string FinalRoomType;
    int Price;

public:
    Reservation(int id, string type, int arrival, int numNights, string roomType);

    //Getters 
    int getID() const;
    string getCustomerType() const;
    int getArrivalTime() const;
    int getNights() const;
    string getRequestedRoomType() const;
    string getAssignedRoomID() const;
    int getCheckInTime() const;
    int getCheckOutTime() const;
    int getWaitingTime() const;
    bool getCancelled() const;
    bool getUpgraded() const;
    string getFinalRoomType() const;
    int getPrice() const;

    int calculatePrice(string type, string room, int nights);
    double calculatePriority(int currentTime, double alpha, double beta) const;

    void assignRoom(string roomID);
    void setCheckInTime(int time);
    void calculateCheckOutTime();
    void cancel();
    void upgrade(string newRoomType);
    void promoteToVIP();
    bool isNoShow(int currentTime, int noShowThreshold) const;
    void print() const;
};

struct VIPComparator {
    int currentTime;
    double alpha;
    double beta;

    VIPComparator(int time, double a, double b);
    bool operator()(const Reservation* r1, const Reservation* r2) const;
};

#endif
