#include<set>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
set<pair<ll,int> > S;
int n,num;
ll temp, ans;

int main(){
    cin>>n;
    cin>>temp;
    S.insert(make_pair(temp,1));
    for(int i = 2; i<= n; i++){
        cin>>temp;
        S.insert(make_pair(temp,i));
        set<pair<ll,int> > :: iterator ite = S.find(make_pair(temp,i) );
        ans = INF;
        if((++ite) != S.end() ){
            ans = (*(ite)).first;
            num = (*(ite)).second;
        }
        if((--ite)!=S.begin() &&  temp-(*(--ite)).first <= ans-temp ){
            ans = (*(ite)).first;
            num = (*(ite)).second;
        }
        cout<<abs(ans-temp)<< ' ' << num<<endl;

    }

}
