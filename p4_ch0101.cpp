#include<iostream>
using namespace std;

int power(int a, int b, int p){
    int ans = 1 % p;
    while(b){
        if(b & 1) ans = (long long) ans * a % p;
        a = (long long ) a * a % p;
        b>>=1;
    }
    return ans;
}

int power2(int a, int b, int p){

    int ans = 1;
    while(b){
        if(b & 1)ans = ans * a %p;
        a = a * a % p;
        b >>= 1;

    }
    return ans;
}

long long mul(long long a, long long b, long long p){
    long long ans = 0;
    while(b){
        if(b & 1) ans = (ans + a)%p;
        a = a*2 %p;
        b >>= 1;

    }
    return ans;
}

int main(){
    cout<<mul(9,9,100);

}
