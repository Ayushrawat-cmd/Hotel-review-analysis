// T.C = O(nlog(n))
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){ // Euclidean algorithm gcd
    // cout<<a<<b;
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
long long lcm(long long a, long long b){ // least common multiple
    return (a/gcd(a,b)) * b;
}
int main(){
    long long ans = 1;
    long long n;
    cin>>n;
    for(long long i =1; i<=n; i++){
        ans = lcm(ans, i); // lcm of all the digits
    }
    cout<<ans;
    return 0;
}