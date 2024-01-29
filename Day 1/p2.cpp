#include<bits/stdc++.h>
using namespace std;
/*
IOT inverter having certain attributes like company name, voltage, current, warranty etc.
*/
class IOTinverter{ 
    string company_name;
    int voltage;
    int current;
    int warranty;

    public:
        IOTinverter() = default;
        IOTinverter(string company_name, int voltage, int current, int warranty){
            this->company_name = company_name;
            this->voltage = voltage;
            this->current = current;
            this->warranty = warranty;
        }
        int powerRating(){
            return this->current*this->voltage;
        }
};

/*
Separate class for solar panel having power rating capaccity attribute
*/
class SolarPanel{
    int power_rating_capacity ;
    public: 
        SolarPanel() = default;
        SolarPanel(int power_rating_capacity){
            this->power_rating_capacity = power_rating_capacity;
        }
};

/*
Separate class for Batter having capacity attribute tells the amount of power can can be stored
*/
class Battery{
    int capacity;
    int number_of_battery;
    public:
    Battery() = default;
    Battery(int capacity, int number_of_battery){
        this->capacity = capacity;
        this->number_of_battery = number_of_battery;
    }

};

/*
Solar invert inherits the property of IOT inverter class 
*/
class SolarInverter:public IOTinverter{
    SolarPanel solarPanel;
    int number_of_solarPanels;
    public:
        SolarInverter() = default;
        SolarInverter(int number_of_solarPanels){
            this->number_of_solarPanels = number_of_solarPanels;
        }
};

/*
Non solar inverter inherits the property of IOT inverter
*/
class NonSolarInverter: public IOTinverter{
    Battery Battery;
    
    public:
        NonSolarInverter(){
            
        }
};

/*
PCU is the type of solar inverter
*/
class PCU: public SolarInverter{
    int charge_controller_rating;
    Battery battery;
    public:
        PCU(){
            charge_controller_rating = 50;
        }
        PCU(int charge_controller_rating){
            this->charge_controller_rating = charge_controller_rating;
        }
};

/*
Grid on is the feature allows to store the power and one can sell it
*/
class GridOn{
    public:

};

/*
GTI inherits the property of solar inverter
*/
class GTI: public SolarInverter{
    GridOn gridOn;
    public:
};

/*
Refalia is the type of solar inverter inherits the property of it 
*/
class Regalia: public SolarInverter{
    public:

};

/*
Zelio is the type of non solar inverter and inherits the properties of it
*/
class Zelio: public NonSolarInverter{
    public:
};

/*
Icruze is the type of non solar inverter and inherits its properties
*/
class Icruze: public NonSolarInverter{
    public:
};
int main(){

}