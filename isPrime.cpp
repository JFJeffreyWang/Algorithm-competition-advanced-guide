#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
bool isPrime(ll x){
    for(int i = 2; i<= sqrt(x); i++){
        if ( x % i == 0) return false;
    }
    return true;
}
int main(){
    ll n;
    while(cin>>n && n){
        for(int i = n; 1; i++){
            if(isPrime(i)){
                cout<<i<<endl;
                break;
            }
        }

    }
}


