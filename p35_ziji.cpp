#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 500005;
int n , a[N], b[N];
ll ans;

void display(){
    for(int i = 1; i<=n;i++){
        cout<<a[i];
    }
    cout<<endl;
}


void Merge(int l, int mid, int r){
    if(l == r)return;
    if(r - l == 1){
        if(a[l]>a[r]){
            swap(a[l], a[r]);
            //display();
            ans++;
        }
        return;
    }
    Merge(l , (l+mid)>>1 , mid);
    Merge(mid+1, (mid+r+1)>>1, r);
    int i = l, j = mid + 1;
    for(int k = l; k <= r; k++){
        if(i>mid || j<=r && a[j]<a[i]){
            b[k] = a[j++];
            ans += mid+1-i;
        }
        else b[k] = a[i++];

    }
   // display();
    for(int k = l; k<= r; k++)a[k] = b[k];

}


int main(){
    while(cin>>n && n){
        for(int i = 1; i<= n; i++){
            cin>>a[i];
        }
        ans = 0;
        Merge(1, (1+n)>>1, n);
        cout<< ans << endl;

    }

}

