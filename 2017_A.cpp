#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define mp make_pair
pair< int,pair<int, pair<int, pair<int, int> > > > Q[305];

int n;
int main(){
    cin>>n;
    int a,b,c;
    for(int i = 1; i <= n; i++){
            cin>>a>>b>>c;
            Q[i] = mp(a+b+c, mp(a, mp(-i, mp(b,c) ) ) );
    }
    sort(Q+1, Q+n+1);
    reverse(Q+1, Q+n+1);
    for(int i =1; i <= 5; i++){
        cout<<-Q[i].second.second.first<<' '<<Q[i].first<<endl;
    }
}
