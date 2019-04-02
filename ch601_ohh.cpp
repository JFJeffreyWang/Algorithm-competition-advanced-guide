#include<iostream>
#include<cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define lll long long

using namespace std;
const int N = 500006;
int n, m, T, a[N], b[N],bl,br;
lll k;

lll value(int l, int r){
    r = (r>n)?n:r;
    if(r<=l){
        return 0;
    }

    for(int i = l; i <= r; i++){
        b[i] = a[i];
    }
    sort(b+l,  b+r+1);

    int M = m;
    lll ans = 0;
    while(l < r && M > 0){
        ans+=(b[l]-b[r])*(b[l++]-b[r--]);
        M--;
    }
    return ans;
}

int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int ans=0;
        for(int i = 1; i<=n; i++)cin>>a[i];
        int l = 1,ll=1, r = 1, p = 1,flag = 1;
        while(flag){
            while(value(l, r)<=k){
                if(r>=n){
                    cout<<ans+1<<endl;
                    flag = 0;
                    break;
                }
                ll = r;
                r += p;
                p *= 2;

            }
            while(r-ll>1 && flag){
                lll temp = value(l,(ll+r)>>1);
                if(temp<=k){
                    ll = (ll+r)>>1 ;
                }
                else {
                    r = ((ll + r)>>1) - 1;
                }
            }
            if(r-ll==1){
                if(value(l,r)<=k)ll==r;
            }
            ans++;
            l = ll+1;
            r = l;
            p = 1;
        }


    }

}



