#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 506;
int n, a[N*N], b[N*N];
#define ll long long
ll ansA, ansB;

ll calc(int l, int mid, int r){

    if(l>=r)return 0;
    if(l==r-1){
        if(a[l]<=a[r])return 0;
        swap(a[l],a[r]);
        return 1;
    }
    ll ans = calc(l, (l+mid)>>1, mid) + calc(mid+1,(mid+r)>>1, r);
    int i = l, j = mid;
    for(int k = l; k <= r; k++){
        if(i>=mid || a[i]>a[j] ){
            b[k] = a[j++];
            ans+=mid-i;
        }
        else{
            b[k] = a[i++];
        }
    }
    return ans;

}

int main(){
    while(cin>>n && n){
        int temp =  n*n;
        for(int i = 1; i <= temp; i++){
                cin>>a[i];
                if(a[i]==0) ansA=1-i;

        }

        ansA += calc(1,(1+temp)>>1,temp);

        for(int i = 1; i <= temp; i++){
                cin>>a[i];
                if(a[i]==0) ansB=1-i;

        }
        ansB += calc(1,(1+temp)>>1,temp);

        if((ansA&1) == (ansB&1) ) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;


    }
}
