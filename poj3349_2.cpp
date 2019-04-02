#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int P = 100003;
const int N = 100009;
int n;
struct snow{
    int six[7];

};
 bool operator == (const snow &a, const snow &b){
        for(int i = 0; i < 6; i++){
            bool same = 1;
            for(int j = 1; j <= 6; j++){
                if(a.six[(j+i)%6+1] != b.six[j]){
                    same = 0;
                    break;
                }
            }
            if(same)return 1;
            same = 1;
            for(int j = 1; j <= 6; j++){
                if(a.six[(-j+i+12)%6+1] != b.six[j]){
                    same = 0;
                    break;
                }
            }
            if(same)return 1;
        }
        return 0;
    }
vector<snow> V[N];
bool C[N];
snow snows[N];

int hash_snow(snow a){
    int ans1= 0,ans2 = 1;
    for(int i = 1; i <= 6; i++){
        ans1 += a.six[i];
        ans2 = (long long )ans2 * a.six[i] % P;
    }
    return (ans1 + ans2) % P;
}
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++)
        cin>>snows[n].six[j];
        int hashNum = hash_snow(snows[n]);
        for(int i = 0; i < V[hashNum].size(); i++){
            if(V[hashNum][i] == snows[n]) {
                cout<<"Twin snowflakes found.";
                return 0;
            }
        }
        V[hashNum].push_back(snows[n]);
    }
    cout<<"No two snowflakes are alike.";
}
