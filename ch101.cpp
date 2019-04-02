#include<iostream>
#define ll long long
using namespace std;

ll a,b,p;

ll power(ll a,ll b,ll p){
    ll ans = 1 % p;
    while(b){
        if(b&1)(ans *= a)%=p;
        (a *= a) %= p;
        b>>=1;
    }
    return ans;
}

int main(){
    cin>>a>>b>>p;
    cout<<power(a,b,p);
}
