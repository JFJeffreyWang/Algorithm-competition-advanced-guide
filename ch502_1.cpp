#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100006;
int x,y,n, X[N], Y[N],s[N];

long long calc(){
    long long ans = 0;
    if(!(n%x)){
        for(int i = 1; i<=x;i++)X[i]-=n/x;
        for(int i = 1; i<=x; i++)s[i] = s[i-1] + X[i];
        sort(s+1,s+1+x);
        for(int i = 1; i<=x/2; i++)ans+=s[x+1-i] - s[i];
    }
    if(!(n%y)){
        for(int i = 1; i<=y; i++)Y[i] -= n/y;
        for(int i = 1; i<=y; i++)s[i] = s[i-1] + Y[i];
        sort(s+1, s + 1 + y);
        for(int i = 1; i <= y/2; i++) ans += s[y + 1 - i] - s[i];
    }
    return ans;
}

int main(){
        cin>>x >>y >> n;
        int a, b;
        for(int i = 1; i <= n; i++){
            cin>>a>>b;
            X[a]++;
            Y[b]++;
        }
        if(n%x){
            if(n%y)cout<<"impossible";
            else(cout<<"column "<<calc());
        }
        else{
            if(n%y)cout<<"row "<<calc();
            else cout<<"both "<<calc();
        }
}
