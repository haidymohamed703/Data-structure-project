#include "RESERVATION.h"
#include <algorithm>
using namespace std;

// Constructor
Reservation::Reservation(int id, string type, int arrival, int numNights, string roomType) {
    ReservationID = id;
    CustomerType = type;
    ArrivalTime = arrival;
    Nights = numNights;
    RequestedRoomType = roomType;
    Price = calculatePrice(type, roomType, numNights);

    AssignedRoomID = "";      
    CheckInTime = -1;
    CheckOutTime = -1;
    WaitingTime = 0;
    IsCancelled = false;
    IsUpgraded = false;
    FinalRoomType = roomType;
}

// Getters
int Reservation::getID() const { return ReservationID; }
string Reservation::getCustomerType() const { return CustomerType; }
int Reservation::getArrivalTime() const { return ArrivalTime; }
int Reservation::getNights() const { return Nights; }
string Reservation::getRequestedRoomType() const { return RequestedRoomType; }
string Reservation::getAssignedRoomID() const { return AssignedRoomID; }
int Reservation::getCheckInTime() const { return CheckInTime; }
int Reservation::getCheckOutTime() const { return CheckOutTime; }
int Reservation::getWaitingTime() const { return WaitingTime; }
bool Reservation::getCancelled() const { return IsCancelled; }
bool Reservation::getUpgraded() const { return IsUpgraded; }
string Reservation::getFinalRoomType() const { return FinalRoomType; }
int Reservation::getPrice() const { return Price; }

// Price Calculation
int Reservation::calculatePrice(string type, string room, int nights) {
    for (auto &c : room) c = tolower(c);
    int baseRoomPrice = (room == "single") ? 2300 : 3600;

    double multiplier;
    if (type == "VIP") multiplier = 2.0;
    else if (type == "REG") multiplier = 1.3;
    else multiplier = 1.0;

    return baseRoomPrice * multiplier * nights;
}

// Priority Calc
double Reservation::calculatePriority(int currentTime, double alpha, double beta) const {
    if (Nights == 0) return 0;
    double denominator = Nights * beta * (currentTime - ArrivalTime + 1);
    if (denominator == 0) return 0;
    return (Price * alpha) / denominator;
}

// Functions
void Reservation::assignRoom(string roomID) { AssignedRoomID = roomID; }

void Reservation::setCheckInTime(int time) {
    CheckInTime = time;
    WaitingTime = time - ArrivalTime;
}

void Reservation::calculateCheckOutTime() {
    if (CheckInTime != -1) {
        CheckOutTime = CheckInTime + Nights;
    }
}

void Reservation::cancel() { IsCancelled = true; }

void Reservation::upgrade(string newRoomType) {
    IsUpgraded = true;
    FinalRoomType = newRoomType;
    Price = calculatePrice(CustomerType, newRoomType, Nights);
}

void Reservation::promoteToVIP() {
    CustomerType = "VIP";
    Price = calculatePrice(CustomerType, FinalRoomType, Nights);
}

bool Reservation::isNoShow(int currentTime, int noShowThreshold) const {
    return (currentTime > ArrivalTime + noShowThreshold) && (CheckInTime == -1);
}

void Reservation::print() const {
    cout << "Reservation ID: " << ReservationID << endl;
    cout << "Customer Type: " << CustomerType << endl;
    cout << "Arrival Time: " << ArrivalTime << endl;
    cout << "Nights: " << Nights << endl;
    cout << "Requested Room: " << RequestedRoomType << endl;

    if (AssignedRoomID != "") cout << "Assigned Room: " << AssignedRoomID << endl;
    if (IsUpgraded) cout << "Upgraded to: " << FinalRoomType << endl;
    if (CheckInTime != -1) {
        cout << "Check-in Time: " << CheckInTime << endl;
        cout << "Check-out Time: " << CheckOutTime << endl;
    }

    cout << "Waiting Time: " << WaitingTime << endl;
    if (IsCancelled) cout << "Status: CANCELLED" << endl;
    cout << "------------------------" << endl;
}

// Comparator
VIPComparator::VIPComparator(int time, double a, double b)
    : currentTime(time), alpha(a), beta(b) {}

bool VIPComparator::operator()(const Reservation* r1, const Reservation* r2) const {
    return r1->calculatePriority(currentTime, alpha, beta) 
         > r2->calculatePriority(currentTime, alpha, beta);
}