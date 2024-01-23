#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
unordered_map<string, vector<string>>mp;
void solve(string &s, int i, string tmp){ // using backtracking to find all the possible outcomes
    int n =s.length();
    if(i == n){
        ans.push_back(tmp);
        return ;
    }
    string tmp1;
    for(int idx=i; idx<n; idx++){
        tmp1+=s[idx];
        // cout<<tmp1<<endl;
        if(mp.find(tmp1) != mp.end()){
            for(auto ele: mp[tmp1]){
                solve(s, idx +1, tmp +ele);
            }
        }
    }
}
int main(){
    mp["1"] = {"Z", "Y", "A"};
    mp["2"] =  {"B", "O"};
    mp["12"] = {"L"};
    mp["3"] = {"U", "P"};
    string s;
    cin>>s; 
    solve(s, 0, "");
    for(auto i: ans){
        cout<<i<<endl;
    }
}