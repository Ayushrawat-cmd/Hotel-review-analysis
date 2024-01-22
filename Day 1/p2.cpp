#include<bits/stdc++.h>
using namespace std;
long long swap_number(long long n){ // function to swap first and last digit 
    int first = n%10; // first number
    int last ;
    long long tmp = n;
    while(tmp){ // hold of last number
        last = tmp%10;
        tmp/=10;
    }
    long long ans = last; // putting value last in ans
    n/=10;
    long long i = 10;
    while(n){ // putting all the values in answer except first and last digit;
        long long rem = n%10;
        if(n/10!= 0)
            ans = rem*i + ans ;
        i*=10;
        n/=10;
    }
    i/=10;
    if(i!=1) // if number having more than one digits than do the following function
        ans = i*first+ans;
    return ans;
}
int main(){
    long long n;
    cin>>n;
    cout<<swap_number(n); // calling swap

}