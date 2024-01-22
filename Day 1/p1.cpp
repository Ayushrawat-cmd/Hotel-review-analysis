#include<bits/stdc++.h>
using namespace std;
bool onlyOneVowel(string &s){ // if there is vowel more than once
    vector<int>a(26,0);
    // vector<int>a(26,0);
    for(auto i: s){
        if(isupper(i))
            a[i-'A']++;
        else
            a[i-'a']++;
    }
    return a[0]+a[4]+a[8]+a[14]+a[21] <=1; // Number_of('a' + 'e' + 'i' +'o' +'u') should be less than equal to one
}
// abcdefghijklmnopqrstuvwyz

bool is_T_Between_2S(string &s){ // check wether there is T between 2 S

    int n =s.length();
    int i = 0, j = n-1;
    for(; i<n && s[i]!='S';){ // check the first time S found
        i++;
    }
    for(; j>=0 && s[j]!='S' ;){ // check the last time S found
        j--;
    }
    if(i == j){ // if there is only one S
        return true;
    }
    i+=1;
    for(; i<j; ){
        if(s[i] == 'T') // there is T between 2 S
            return false;
        i++;
    }
    return true;// No T found
}
int main(){
    string s;
    cin>>s;
    if(onlyOneVowel(s) && is_T_Between_2S(s)){
        cout<<"Valid";
    }
    else{
        cout<<"Not valid";
    }
}