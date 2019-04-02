#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int  P = 9901,Q = P, ans = 0, a, b;
vector<int> primes;
const int N= 50000005;
bool v[N];

void prime(){
    for(int i = 2; i <= a; i++){
        if(v[i])continue;
        primes.push_back(i);
        for(int j = 2; j <= a/i; j++) v[j*i] = 1;
    }

}

int power(int a, int b){
    int ans = 1 % P;
    a %= P;
    while(b){
        if(b & 1) (ans *= a)%=P;
        (a *= a)%= P;
        b>>=1;
    }
    return ans;
}


int sum(int  p, int c){
    //cout<<p<< ' ' << c<<endl;
    if(!p) return 0;
    if(!c) return 1;
    if(c&1) return sum(p,c/2)*(1+power(p,c/2+1)) % Q;
    return ((long long ) sum(p, c/2-1) * (1+power(p, c/2+1)) + power(p, c/2))%Q;
}

int sumdiv(int a, int b){
    int ans= 1;

    for(int i = 0; i < primes.size() && primes[i] <= a ; i++){
        int cnt = 0;
        while(!(a%primes[i]) ){
            a /= primes[i];
            cnt++;
        }
        if(cnt)(ans *= sum(primes[i], b*cnt))%=Q;
    }
    return ans;

}

int main(){
    cin>> a>>b;
    prime();
    cout<<sumdiv(a,b);

}
