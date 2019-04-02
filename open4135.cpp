#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 100006;
int n, m, a[N];
ll total, l, r, mid;

bool calc(ll x){
    int i = 1;
    for(int mon = 1; mon <=m; mon++){
        int cnt = 0;
        while(i <= n && cnt+a[i]<=x ){
            cnt+=a[i++];
        }
        if(i==n+1)return 1;
    }
    return 0;
}


int main(){
    cin>>n>>m;
    for(int i = 1; i<= n; i++){
        cin>>a[i];
        total+=a[i];
    }
    r = total;
    while(l<r){
       int mid = (l+r)>>1;
        if(calc(mid)){
            r = mid;
            continue;
        }
        else{
            l = mid+1;
            continue;
        }

    }
    cout<<l;
}
