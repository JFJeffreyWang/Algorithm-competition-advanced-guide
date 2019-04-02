#include<iostream>
#include<cstring>
using namespace std;
void prime(int n){
    bool N[n+5];
    memset(N,0,sizeof(N));
    for(int i=2;i<=n;i++){
        if(N[i])continue;
        cout<<i<<endl;
        for(int j=i;j<=n/i;j++){
            N[j*i] = 1;
        }
    }
}

int main(){
    prime(100);
}
