#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll p,q,r;

ll toten(ll i, ll b){
   // cout<<"toten "<<i<<' '<<b<<endl;

    ll ans = 0;
    int a[30], num = 0;

    while(i){
        a[num++] = i%10;
        if(a[num-1] >= b){
       //     cout<<"a[num-1] "<<a[num-1] <<' '<<b <<endl;
            return -3;
        }
        i = i/10;

    }
    for(int i = num-1; i>=0; i--){
        ans = ans*b + a[i];
    }
    return ans;
}

int main(){
    cin >> p >> q>>r;
    for(int i = 2; i <= 16 ;i++){
      //  cout<<i<<' '<<toten(p,i)<<' '<<toten(q,i) <<' '<< toten(r,i)<<' '<<endl;
        int pp =toten(p,i);
        if(pp==-3)continue;
        int qq = toten(q,i);
        if(qq == -3)continue;
        int rr = toten(r,i);
        if(rr == -3)continue;
        if( pp*qq == rr){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}
