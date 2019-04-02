#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define mp make_pair

int n,a,b;
set<pair<int,int> > S;
int main(){
    cin>>n;
    S.insert(mp(1000000000,1));
    while(n--){
        cin>>a>>b;
        cout<<a<<' ';

        set<pair<int,int> > ::iterator ite = S.upper_bound(mp(b, a));
        set<pair<int,int> > ::iterator ite2 = S.upper_bound(mp(b, a));
        ite2--;
        if(ite == S.end()){
            cout<<(*ite2).second;
        }
        else if(ite == S.begin()){
            cout<<(*ite).second;
        }
        else if( (*ite).first - b >= b - (*ite2).first){
            cout<<(*ite2).second;
        }
        else cout<<(*ite).second;
        cout<<endl;
        S.insert(mp(b, a));

    }
}
