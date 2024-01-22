// T.C = O(n*(10))
// S.C O(1)
#include<bits/stdc++.h>
using namespace std;
bool prime(int n ){ // function to check if all digits prime or not
    while(n){
        int rem = n%10;
        if(rem!=2 && rem!= 3 && rem!=5 && rem != 7 ) // if digit is not 2 and 3 and 5 and 7 then it is not prime
            return false;
        n/=10;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(n<=2){
        cout<<"Not found";
        return 0;
    }
    for(int i=n-1; i>=2; i--){
        if(prime(i)){ // calling prime
            cout<<i;
            return 0;
        }
    }
    return 0;
}