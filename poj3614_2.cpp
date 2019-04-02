#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
const int INF = 0x3f3f3f3f;
priority_queue<pair<int, int> > Qcow;
multiset<int> S;
int C, L, ans;

int main(){
    cin>>C>>L;
    int a,b;
    while(C--){
        cin>>a>>b;
        Qcow.push(make_pair(a, b));
    }
    while(L--){
        cin>>a>>b;
        while(b--)
        S.insert(a);
    }
    while(Qcow.size()){
        a = Qcow.top().first;
        b = Qcow.top().second;
        Qcow.pop();
        multiset<int> ::iterator ite = S.upper_bound(b);
        if(ite != S.begin()){
            ite--;
            if((*ite) >=a){
                    // cout<<"test"<<a<<' '<<b<<' '<< (*ite)<<endl;
                S.erase(ite);
                ans++;

            }
        }

    }
    cout<<ans;
}

