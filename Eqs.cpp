#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long
int q[7],cnt;
const int P = 1000003;
vector<ll> Q[P+5];
bool v[P+5];



int main(){
    for(int i = 1; i <= 5; i++){cin>>q[i];    }
    for(int a = -50; a<=50; a++){
        if(a==0)continue;
        for(int b = -50; b <= 50; b++){
            if(b==0)continue;
                    ll temp = (ll)q[1]*a*a*a + (ll)q[2]*b*b*b ;
                    int hn = ((temp%P)+P)%P;
                    v[hn] = 1;
                    Q[hn].push_back(temp);
        }
    }

    for(int a = -50; a <= 50; a++){
        if(a==0)continue;
        for(int b = -50; b <= 50; b++){
            if(b==0)continue;
            for(int c = -50; c <= 50; c++){
                if(c==0)continue;
                ll temp = -(ll)q[3]*a*a*a - (ll)q[4]*b*b*b  - (ll)q[5]*c*c*c ;
                int hn = ((temp%P)+P)%P;
                if(v[hn]){
                    for(int i = 0; i < Q[hn].size(); i++){
                        if(temp == Q[hn][i])cnt++;
                    }

                }
            }
        }
    }

    cout<<cnt;
}
