#include<bits/stdc++.h>
using namespace std;
const regex pattern ("((http(s)?)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
bool valid_url(string s){
    for(auto i : s){
        if(i==' ')
            return false;
    }
    if(regex_match(s, pattern)){
        return true;
    }
    return false;
}
int main(){
    string s;
    getline(cin, s);
    if(valid_url(s))
        cout<< "Valid";
    else
        cout<<"Not valid";

    // cout<<s;
}
