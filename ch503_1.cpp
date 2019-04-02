#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 250006;
int n,a[N],b[N];

long long Merge(int l, int m, int r){

    if(r-l <= 0)return 0;
    if(r-l == 1){
            if(a[l]<=a[r])return 0;
            else{
                swap(a[l],a[r]);
                return 1;
            }
    }
    long long ans = 0;
    ans += Merge(l, (l+m)>>1, m);
    ans += Merge(m+1, (m+1+r)>>1, r);
    int i = l,j = m+1, num = l;
    while(num<=r){
        if(j>r || i<=m && a[i]<=a[j]){
            b[num++] = a[i++];
        }
        else{
            b[num++] = a[j++];
            ans += m-i+1;
        }
    }
    for(int i = l; i<=r; i++){
        a[i] = b[i];
    }
    return ans;
}

bool calc(){
    bool flag = 0;
    for(int i = 1; i <= n*n-1; i++){
        cin>>a[i];
        if(!a[i]){
            cin>>a[i];
            flag = 1;
        }
    }
    if(!flag){
        cin>>a[0];
    }
    return Merge(1,(n*n)>>1,n*n-1) & 1;

}

int main(){
    while(cin>>n && n){
        if(calc()^calc()) cout<<"NIE"<<endl;
        else cout<<"TAK"<<endl;
    }


}
int m2ain(){
    for(int i = 1; i<= 100; i++){
        a[i] = i;
    }
    a[50] = 0;
    cout<<Merge(1,49,100);

}
