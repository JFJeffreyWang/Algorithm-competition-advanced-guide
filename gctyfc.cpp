#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int k, n;
int kp(int a, int b, int p){
    int ans = 1 % p;
    a = a%p;
    while(b){
       if(b&1) ans = (long long)ans * a % p;
        (a *=a)%=p;
        b>>=1;
    }
    return ans;
}

int main(){
    cin>>k>>n;
    for(int i = 1; i < n; i++){
        if(kp(i,k,n)==1)cout<<i<<endl;
    }

}
