#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
const int N = 500005;
ll a[N], n, m, k, b[N];
int T,bl, br;
int INF = 0x3f3f3f3f;

int calc(int qidian, int l, int mid, int r){
    if(mid>n) mid = n;
    if(l+1==r || l >= n){
            //cout<<"test return: "<< l << endl ;
            return l;}
    if(bl!=qidian || br> mid){
        for(int i = qidian; i <= mid; i++){
            b[i] = a[i];
        }
        sort(b+qidian, b+mid+1);
        bl = qidian;
        br = mid;
    }
    else{
        for(int i = br+1; i<= mid; i++){
            b[i] = a[i];
        }
        sort(b+qidian, b+mid+1);
        br = mid;
    }
    ll ans = 0;
    for(int i = 1; i <= m && 2*i<=mid-qidian+1 && ans <= k ; i++){
        ans += (b[mid-i+1]-b[qidian+i-1])*(b[mid-i+1]-b[qidian+i-1]);
    }

   // cout<<"test " <<qidian  << ' '<< l << ' '<<mid<< ' '<<r<< ' '<<ans<<endl;
    if(ans>k) return calc(qidian, l, (l+mid)>>1, mid);
    if(r == INF) return calc(qidian, mid, mid+(mid-l)*2, r);
    return calc(qidian, mid, (mid+r)>>1, r);
}

int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        bl = -1;
        for(int i = 1; i <= n; i++)cin>>a[i];
        int i = 1, ans = 0;
        while(i<=n){
            i = calc(i, i, i+3, INF)+1;
            ans++;
        }
        cout<<ans<<endl;



    }
}
