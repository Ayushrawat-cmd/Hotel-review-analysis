

#include<bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

/*
User class having properties of user
*/
class User{
    int userId;
    string name;
    int age;
    public:
        User() =default;
        User(string name, int age , int id){
            this->name = name;
            this->age = age;
            this->userId = id;
        }
        int get_userID(){
            return userId;
        }

};

/*
Vehicle is the class which is the base class of the cars, trucks, wheelchair etc.
*/
class Vehicle{
    int vehicleId;
    public:
        Vehicle() = default;
        Vehicle(int vehicleId){
            this->vehicleId = vehicleId;
        }
};

/*
Car is the subclass of vehicle
*/
class Car: public Vehicle{
    string nameplate;
    public:
        Car() = default;
        Car(string nameplate){
            this->nameplate = nameplate;
        }
};

/*
Truck is the subclass of the vehicle
*/
class Truck: public Vehicle{
    string nameplate;
    public:
        Truck() = default;
        Truck(string nameplate){
            this->nameplate = nameplate;
        }
};

/*
Motor cycle is a vehicle
*/
class MotorCycle: public Vehicle{
    string nameplate;
    public:
        MotorCycle() = default;
        MotorCycle(string nameplate){
            this->nameplate = nameplate;
        }
};

/*
Wheel chair is vehicle
*/
class Wheelchair: public Vehicle{
    int size;
    public:
        Wheelchair() = default;
        Wheelchair(int size){
            this->size = size;
        }
};

/*
Electric car is a car. It is the grandchild class of the vehicle
*/
class ElectricCar: public Car{
    string color;
    public:
        ElectricCar() = default;
        ElectricCar(string color){
            this->color = color;
        }
};

/*
It have the occupied property which tells that wehter that spot is occupied or not
*/
class ParkingSpot{
    int place;
    bool occupied;
    public:
        ParkingSpot() = default;
        ParkingSpot(int place){
            this->place = place;
            occupied = 0;
        }
        void spotOccupy(){
            occupied = 1;
        }
        void spotUnoccupy(){
            occupied = 0;
        }
        bool isOccupied(){
            return occupied;
        }
        int getSpot(){
            return place;
        }
};

/*
Compact is a type of Parking spot
*/
class Compact: public ParkingSpot{
    Vehicle car = Car();
    bool occupied;
    int place;
    public:
        Compact(){

        }
        void spotOccupy(){
            occupied = 1;
        }
        void spotUnoccupy(){
            occupied = 0;
        }
        bool isOccupied(){
            return occupied;
        }
        int getSpot(){
            return place;
        }
};

/*
Large is type of parking spot
*/
class Large: public ParkingSpot{
    Vehicle truck = Truck(); // Its having the object of the truck
    bool occupied;
    int place;
    public:
        Large(){

        }
        
        void spotOccupy(){
            occupied = 1;
        }
        void spotUnoccupy(){
            occupied = 0;
        }
        bool isOccupied(){
            return occupied;
        }
        int getSpot(){
            return place;
        }
};

/*
Handicapped is the type of parking spot
*/
class Handicapped: public ParkingSpot{
    Vehicle wheelchair = Wheelchair();
    bool occupied;
    int place;
    public:
        Handicapped(){

        }
        
        void spotOccupy(){
            occupied = 1;
        }
        void spotUnoccupy(){
            occupied = 0;
        }
        bool isOccupied(){
            return occupied;
        }
        int getSpot(){
            return place;
        }
};

/*
Motorcycle spot is the type of parking spot 
*/
class MotorCycleSpot: public ParkingSpot{
    Vehicle motorCycle = MotorCycle();
    bool occupied;
    int place;
    public:
        MotorCycleSpot(){

        }
        
        void spotOccupy(){
            occupied = 1;
        }
        void spotUnoccupy(){
            occupied = 0;
        }
        bool isOccupied(){
            return occupied;
        }
        int getSpot(){
            return place;
        }
};

/*
Electric car spot is the type of parking spot
*/
class ElectriccarSpot: public ParkingSpot{
    Vehicle electricCar = ElectricCar();
    int charge;
    bool occupied;
    int place;
    public:
    
        void spotOccupy(){
            occupied = 1;
        }
        void spotUnoccupy(){
            occupied = 0;
        }
        bool isOccupied(){
            return occupied;
        }
        int getSpot(){
            return place;
        }

};

/*
Parking floor has many parking spots
*/
class ParkingFloor{ 
    vector<ParkingSpot> parkingSpots; 
    vector<Compact>compactSpots;
    vector<Compact>compactStops;
    vector<Compact>compactStops;
    vector<Compact>compactStops;
    int parking_spots;
    vector<vector<int>>userPaidID; // user paid through exit panels
    int num_of_entrypoints, num_of_exitpoints;
    int floor;
    public:
        ParkingFloor() = default;
        ParkingFloor (int max_parking_spots, int num_of_entrypoints, int num_of_exitpoints, int floor){
            this->parking_spots = max_parking_spots;
            this->num_of_entrypoints = num_of_entrypoints;
            this->num_of_exitpoints = num_of_exitpoints;
            this->floor = floor;
        }   
        int addParkingSpots(int spot_location){
            parkingSpots[spot_location].spotUnoccupy();
            this->parking_spots +=1;
            return this->parking_spots;
        }
        int removeParkingSpot(int spot_location){
            parkingSpots[spot_location].spotOccupy();
            this->parking_spots -=1;
            return this->parking_spots;
        }
        vector<ParkingSpot> getParkingSpots(){
            return this->parkingSpots;
        }
        void displayParkingSpots(){
            cout<<"Number of parking Spots:- "<<parking_spots;
        }
        void paidUsingExitPanel(int userID, int exitPoint){
            userPaidID[exitPoint].push_back(userID);
        }
        int getFloor(){
            return floor;
        }
};

class Price{
    int first_hour_fee;
    int second_Third_hour_fee;
    int remaining_hour_fee;
    public:
        Price(){
            first_hour_fee = 4;
            second_Third_hour_fee =3.5;
            remaining_hour_fee =2.5;
        }   
        vector<int>fees(){
            return {first_hour_fee ,second_Third_hour_fee, remaining_hour_fee};
        }

        int charge(int checkin, int checkout){
            int hours = checkout -checkin;
            if(hours>3){
                return remaining_hour_fee*hours;
            }
            else if(hours>=2)
                return second_Third_hour_fee*hours;
            else
                return first_hour_fee;
        }
};


class System{
    int max_parking_floor;
    int max_parking_attendant;
    vector<ParkingAttendant>parkingAttendants ;
    vector<ParkingFloor> parkingFloors;
    vector<Customer>customers;
    Price fee;
    public:
        System() = default;
        System(int max_parking_floor, int max_parking_attendant){ // Maximum floor and maximum parking attendant should be there in system
            this->max_parking_floor = max_parking_floor;
            this->max_parking_attendant = max_parking_attendant;
            parkingFloors.reserve(max_parking_floor);
            parkingAttendants.reserve(max_parking_attendant);
        }
        int addParkingFloor(ParkingFloor & parkingFloor){ // Add floor in the system
            if(parkingFloors.size() == max_parking_floor)
                return false;
            parkingFloors.push_back(parkingFloor);
            return parkingFloors.size();
        }
        int removeParkingFloor(int floor){ // Remove floor from the system
            for(int i =0; i<parkingFloors.size(); i++){
                if(floor == parkingFloors[i].getFloor()){
                    swap(parkingFloors[i], parkingFloors[parkingFloors.size()-1]);
                    break;
                }
            }
            parkingFloors.pop_back();
            return parkingFloors.size();
        }
        int removeSpotFromFloor(int floor, int spot_location){ // remove spot from the floor at dedicate floor of fixed location
            return parkingFloors[floor].removeParkingSpot(spot_location);
        }
        int addSpotInFloor(int floor, int spot_location){ // add spot in the floor at dedicate location
            
            return parkingFloors[floor].addParkingSpots(spot_location);
        }   
        int addParkingAttendant(ParkingAttendant &parkingAttendant){ // add parking attendant in the system
            max_parking_attendant+=1;
            parkingAttendants.push_back(parkingAttendant);
            return max_parking_attendant;
        }
        int removeParkingAttendant(int attendantID){ // remove attendant from the system
            int idx = 0;
            for(ParkingAttendant parkingAttendant: parkingAttendants  ){
                
                if(parkingAttendant.get_userID() == attendantID){
                    break;
                }
                idx++;
            }
            swap(parkingAttendants[idx], parkingAttendants[max_parking_attendant-1]); // swap with the last one and pop it from vector
            parkingAttendants.pop_back();
            max_parking_attendant-=1;
            return max_parking_attendant;
        }
        bool parkingSpotAvailable(Vehicle &vehicle){ // check if the spot is availaible or not
            bool available = 0;
            for(ParkingFloor floor: parkingFloors){
                for(ParkingSpot spots: floor.getParkingSpots()){
                    if(!spots.isOccupied()){
                        available = 1;
                        break;
                    }
                }
            }
            if(available){
                return true;
            }
            return false;
        }
        bool addCustomer(Customer &customer){ // add customer in the system
            Vehicle vehicle =customer.getVehicle();
            if(this->parkingSpotAvailable(vehicle)){
                customers.push_back(customer);
                for(int i=0; i<max_parking_floor; i++){
                    vector<ParkingSpot>parkingSpots = parkingFloors[i].getParkingSpots();
                    for(int j =0; j<parkingSpots.size(); j++){
                        if(parkingSpots[j].isOccupied()){
                            this->removeSpotFromFloor(parkingFloors[i].getFloor(), parkingSpots[j].getSpot());
                            break;
                        }
                    }
                }
                customers[customers.size()-1].checkinTime(randint(1,10));
                return true;
            }   
            return false;
        }
        bool removeCustomer(Customer &c, ParkingSpot & parkingSpot, ParkingFloor & parkingFloor){ // basically it will not remove customer of the system it just add the checkout time in the system for respective customer
            int idx= 0;
            for(auto customer: customers){
                if(customer.get_userID() == c.get_userID()){
                    break;
                }
                idx++;
            }
            if(idx == customers.size())
                return false;
            customers[idx].checkoutTime(10); // right now the checkout time is static
            parkingFloors[parkingFloor.getFloor()].addParkingSpots(parkingSpot.getSpot()); // unoccupy the spot
        }
        int chargePay(Customer &customer){ // charge paid by the customer
            return fee.charge(customer.getCheckinTime(), customer.getCheckoutTime());
        }
        int addPayment(Customer &c, string feesPaidTo,ParkingAttendant & parkingattendant){ // add payment in system
            int idx =0 ;
            for(auto parkingAttendant: parkingAttendants){
                if(parkingAttendant.get_userID() == parkingattendant.get_userID())
                    break;
                idx++;
            }
            if(feesPaidTo == "parkingattendant"){
                parkingAttendants[idx].user_paid(c.get_userID());
            }
        }
};

/*
Admin class which is the user and have the system
*/
class Admin: public User{
    int parking_rate;
    
    public:
        System*system;
        Price *price; // admin has Price object which helps him to modify the charge
        Admin(int parking_rate){
            this->parking_rate = parking_rate;
        }
        int addParkingRate(int rate){ // add parking rate 
            this->parking_rate+=rate;
        }
        int modifyParkingRate(int parkingRate){ // modify the rate
            this->parking_rate =parking_rate;
        }
};

/*
Customer is the user which have vehicle and allocated floor and the spot
*/
class Customer: public User{
    Vehicle vehicle;
    string payment_type;
    int checkin;
    int checkout;
    string paidTo;
    int paid_fee;
    // int amount_paid;
    ParkingFloor parkingFloor;
    ParkingSpot parkingSpot;
    ParkingAttendant parkingAttendant;
    public:
        Customer(Vehicle &vehicle, string payment_type){
            this->vehicle = vehicle;
            this->payment_type = payment_type;
        }
        Vehicle getVehicle(){
            return vehicle;
        }
        int  checkoutTime(int time){
            checkout = time;
            return checkout;
        }
        int checkinTime(int time){
            checkin = time;
            return checkin;
        }
        int getCheckoutTime(){
            return checkout;
        }
        int getCheckinTime(){
            return checkin;
        }
        void payment(string paidTo, int fees){ // this is for payment done to parking attendant right now
            this->paidTo = paidTo;
            this->paid_fee = fees;
            parkingAttendant.user_paid(this->get_userID());
        }
        string feesPaidTo(){
            return paidTo;
        }
        int amountPaid(){
            return paid_fee;
        }

};
class ParkingAttendant: public User{
    vector<int>paid_userID; // all the ids of the user who paid to this parking attendant
    public:
        ParkingAttendant() = default;
        void user_paid(int userID){ 
            paid_userID.push_back(userID);
        }
};
int main(){

}