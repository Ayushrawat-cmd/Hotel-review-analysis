#include<bits/stdc++.h>
using namespace std;
const regex pattern ("((http(s)?)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)"); // regex pattern for valid url
bool valid_url(string s){
    for(auto i : s){
        if(i==' ') // space then invalid
            return false;
    }
    if(regex_match(s, pattern)){// if pattern match then true
        return true;
    }
    return false;
}
int main(){
    string s;
    getline(cin, s); // enter line
    if(valid_url(s)) // check for validity
        cout<< "Valid";
    else
        cout<<"Not valid";

    // cout<<s;
}
