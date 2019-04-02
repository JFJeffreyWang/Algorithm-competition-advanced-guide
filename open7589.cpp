#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100003;
bool v[N];

int rev(int x){
    int ans = 0;
    while(x){
        ans = ans*10 + x%10;
        x/=10;
    }
    return ans;
}

void prime(){
    v[1] = 1;
    for(int i = 2; i <= N; i++){
        if(v[i])continue;
        for(int j = 2; j <= N/i; j++)v[i*j] = 1;
    }

}

int main(){
    prime();
    int l, r;
    cin>>l>>r;
    bool flag = 0;
    for(int i = l+1; i <= r; i++){
        if(!v[i] && !v[rev(i)]){
                if(flag)cout<<',';
                cout<<i;
                flag = 1;
        }
    }

}
