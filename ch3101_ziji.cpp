#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> prime;
int n;

void primes(){
    bool v[n+4];
    memset(v,0,sizeof(v));
    for(int i = 2; i <= n; i++){
        if(v[i])continue;
        prime.push_back(i);
        for(int j = 2; j <= n/i; j++){
            v[i*j] = 1;
        }
    }
}

int main(){
    cin>>n;
    primes();
    for(int i = 0; i < prime.size();i++){
        int p = prime[i],c= 0;
        for(int j = n; j; j/=p) c+=j/p;
        cout<<p<<' '<<c<<endl;
    }
}

