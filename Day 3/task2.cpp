#include<bits/stdc++.h>
using namespace std;

/*
Denomination class holds all the types of notes in the atm
*/
class Denomination{
    map<int ,int, greater<int> >num_of_notes; // it will stores the number of notes in descending order of the denomination
    int total_money; // total money holds in the atm
    public:
        Denomination(){
            num_of_notes[2000] = 0;
            num_of_notes[500] = 2000;
            num_of_notes[200] = 2000;
            num_of_notes[100] = 2000;
        }
        Denomination(int value_of_cash, int num_of_cash){ 
            num_of_notes[value_of_cash] = num_of_cash;
            total_money += value_of_cash*num_of_cash;
        }
        void addMoney(int value_of_cash, int num_of_cash){ // add the number of cash for the respective denomination 
            num_of_notes[value_of_cash] += num_of_cash;
            total_money += value_of_cash*num_of_cash;
        }
        void removeMoney(int value_of_cash, int num_of_cash){ // remove the number of cash for the respective denomination 
            num_of_notes[value_of_cash] -= num_of_cash;
            total_money -= value_of_cash*num_of_cash;
        }
        bool availableForFixedCash(int value_of_cash, int num_of_cash){ // is cash availaible for the respective denomination
            return num_of_notes[value_of_cash]>=num_of_cash;
        }
        bool available(int amount){ // is total amount availaible
            return total_money>=amount;
        }
        vector<int>typesOfAvailableCash(){ // return the types of availaible cash
            vector<int>temp;
            for(auto i: num_of_notes){
                temp.push_back(i.first);
            }
            return temp;
        }
        int numberOfCash(int value_of_cash){ // return number of cash for the given denomination
            return num_of_notes[value_of_cash];
        }
};
class ATM{
    Denomination *denomination;
    public:
        ATM(){
            denomination = new Denomination(); // initialise the object
        }
        int withDraw(int amount){ // withdrawing the money from atm
            if(!(denomination->available(amount))){ // is the amount available in atm
                vector<int>available_cash = denomination->typesOfAvailableCash();
                vector<pair<int,int>>temp; // it stores temprorarily the number of cashes with respect to the value of cash
                for(int value_of_cash: available_cash){ 
                    int num_of_cash = amount/value_of_cash;
                    if(denomination->availableForFixedCash(value_of_cash, num_of_cash)){ // is the cash available for the given denomination
                        amount -= num_of_cash*value_of_cash;
                        if(num_of_cash)
                            temp.push_back({value_of_cash, num_of_cash});
                    }
                }
                if(amount){ // if amount is still left then it means it is not the multiple of the availaible denominations
                    cout<<"The given amount is not available according to given denominations\n";
                }
                else{
                    for(auto ele: temp){
                        if(ele.second){
                            denomination->removeMoney(ele.first,ele.second); // reduce the number of cash for the respective denomination 
                            cout<<ele.first<<" X "<<ele.second<<" \t";
                        }
                    }
                    cout<<"\n";
                }
            }
            else{
                cout<<"Insufficient amount of money\n";
            }
        }
        int topUp(int amount){ // top up the amount
            vector<int>available_cash = denomination->typesOfAvailableCash();
            vector<pair<int,int>>temp; // it stores temprorarily the number of cashes with respect to the value of cash
            for(int value_of_cash: available_cash){
                int num_of_cash = amount/value_of_cash;
                amount -= num_of_cash*value_of_cash;
                temp.push_back({value_of_cash, num_of_cash});
            }
            if(amount){
                cout<<"The given amount is not available according to given denominations\n";
            }
            else{
                for(auto ele: temp){
                    denomination->addMoney(ele.first,ele.second); // add the cnumber of cash for the respective denomination
                    if(ele.second)
                        cout<<ele.first<<" X "<<ele.second<<"\t";
                }
                cout<<"\n";
            }
        }
        void atmDetails(){ // displays all the details of the atm
            vector<int>available_cash = denomination->typesOfAvailableCash(); 
            for(int value_of_cash: available_cash){
                cout<<value_of_cash<<" X "<<denomination->numberOfCash(value_of_cash)<<"\t";
            }
            cout<<"\n";
        }

};
int main(){
    ATM atm;
    cout<<"Top up the atm:- ";
    int amount ;
    cin>>amount;
    atm.topUp(amount);
    atm.atmDetails();
    cout<<"Withdraw amount:- ";
    cin>>amount;
    atm.withDraw(amount);
    atm.atmDetails();
    // atm.
}