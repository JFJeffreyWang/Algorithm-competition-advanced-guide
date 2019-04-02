#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
long long ans,f[60006];
int main(){
    cin>>n;
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i-1; j++){
            f[i]+=f[j]*f[i-1-j];
        }
    }
    cout<<f[n];
}
