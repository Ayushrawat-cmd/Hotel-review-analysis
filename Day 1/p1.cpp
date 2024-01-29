#include<bits/stdc++.h>
using namespace std;

/*
class of person having the name attribute and have getname feature
*/
class Person{
    string name;
    public:
        Person(){
            cout<<"Enter name:- ";
            cin>>name;
        }
        string getName(){
            return name;
        }
        void printBio(){
            cout<<"Name:- "<<name<<"\n";
        }
};

/*
class of vehicle having certain attributes
*/
class Vehicle{
    int tire_loadRating;
    int tire_pressure;
    int speed;
    public:
        Vehicle() = default;
        Vehicle(int tire_loadRating, int tire_pressure, int speed){
            this->tire_loadRating = tire_loadRating;
            this->tire_pressure = tire_pressure;
            this->speed= speed;
        }
};

/*
class aircraft is inheriting the properties of vehicle
*/
class Aircraft: public Vehicle{
    string brand_name;
    public:
    Aircraft() =default;
    Aircraft(string brand_name){
        this->brand_name = brand_name;
    }
};

/*
Similarly car is inheriting the vehicle property
*/
class Car: public Vehicle{
    string brand_name;
    public:
    Car() =default;
    Car(string brand_name){
        this->brand_name = brand_name;
    }
};

/*
Driver is a person
*/
class Driver: public Person{
    int rating;
    public: 
        Driver() = default;
        Driver(int driver_rating){
            rating = driver_rating;
        }
};

/*
MP is a person
*/
class MP :  public Person{
    Driver driver;
    Car car;
    string constituency;
    int spendingLimit;
    public:
        MP(){
            spendingLimit = 100000;
        }
        MP(int costLimit, string constituency){
            spendingLimit = costLimit;
            this->constituency = constituency;
        }
        void setSpendingLimit(int spendingLimit){
            this->spendingLimit = spendingLimit;
        }
        void printDriverBio(){
            driver.printBio();
        }
        int getExpenseLimit(){
            return spendingLimit;
        }
};

/*
Multi level inheritance is going on here. Minister is the MP.
*/
class Minister: public MP{
    string name_of_ministry;
    public:
        Minister() {
            setSpendingLimit(1000000);
        }
        Minister(string name_of_ministry){
            this->name_of_ministry = name_of_ministry;
        }
};

/*
Prime minister is the minister
*/
class PrimeMinister: public Minister{
    int number_of_ministry;
    Aircraft aircraft;
    Driver aircraft_Driver;
    public:
        PrimeMinister(){
            setSpendingLimit(10000000);
        }
        PrimeMinister(int number_of_ministry){
            this->number_of_ministry = number_of_ministry;
        }
};

/*
Commisioner is the person and inheriting its properites
*/
class Commisioner: public Person{
    string dept_name;
    Driver driver;
    unordered_map< string,int>parliament_map; // type of the parliament member

    public:
        Commisioner(string dept_name){
            parliament_map["mp"]=1;
            parliament_map["minister"] = 2;
            parliament_map["primeMinister"] = 3;
            this->dept_name = dept_name;
        }
        void printDriverBio(){
            driver.printBio();
        }
        bool canArrest(int limit, int expense, bool primeMinister_permission, string type_of_mp){ // function tells that MP can arrest by the commisioner or not
            if(parliament_map[type_of_mp] == 0){
                return limit<expense;
            }
            else if(parliament_map[type_of_mp] == 1 && primeMinister_permission){
                return expense>limit;
            }
            return false;
        }
};
int main(){
    // Commisioner commisioner;
    int number_of_ministers;
    cout<<"How many number of ministers there are? ";
    cin>>number_of_ministers;
    cout<<"Enter details of minister:- \n";
    vector<Minister>ministers(number_of_ministers);
    for(auto minister: ministers){
        minister.printBio();
    }
    cout<<"\n\n";
    ministers[0].printDriverBio();

    cout<<"\n\n";
    cout<<"Enter details of Commisioner:- \n";
    Commisioner commisioner("delhi");
    cout<<"Details of driver of commisioner "<<commisioner.getName()<<":- \n";
    // commisioner.setDriverBio();
    MP mp = Minister();
    
    // vector<

}