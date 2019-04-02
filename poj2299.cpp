#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
const int N = 500000+5;
int n, a[N], b[N];

ll calc(int l, int mid, int r){
    if(l==r)return 0;
    if(l==r-1){
        if(a[l]<=a[r])return 0;
        swap(a[l], a[r]);
        return 1;
    }
    ll ans =calc(l,(l+mid)>>1, mid) + calc(mid, (mid+r)>>1, r);
    int i = l, j = mid;
    for(int k = l; k <= r; k++){
        if(i>=mid || a[i] > a[j]){
            b[k] = a[j++];
            ans+=mid-i;
        }
        else{
            b[k] = a[i++];
        }
    }

     for(int k = l; k <= r; k++){
        a[k] = b[k];
    }

    return ans;

}
int main(){
    while(cin>> n && n){
        for(int i = 1; i<= n; i++){
            cin>>a[i];
        }
        cout<<calc(1,(1+n)>>1, n)<<endl;


    }
}
