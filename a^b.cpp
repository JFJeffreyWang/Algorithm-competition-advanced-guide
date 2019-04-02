#include<iostream>
using namespace std;
#define ll long long
int power(int a, int b, int p){
    int ans = 1 % p;
    while(b){
        if(b&1) ans = (long long )ans * a % p;
        a = (long long) a * a % p;
        b >>= 1;
    }
    return ans;
}

long long mul(ll a, ll b, ll p){
    ll ans = 0;
    while(b){
        if(b&1)ans = (long long )(ans + a) % p;
        a =(long long) a * 2 % p;
        b >>= 1;
    }
    return ans;
}

int main(){
    unsigned int q = 0xffffffff;
    cout<<q;
    int n, m;
    cin>>n;
    ll a, b ,p;
    while(n--){
        cin>>p>>m;
        ll ans = 0;
        while(m--){
            cin>>a>>b;
            (ans += power(a,b,p))%=p;
        }
        cout<<ans<<endl;

    }



}
