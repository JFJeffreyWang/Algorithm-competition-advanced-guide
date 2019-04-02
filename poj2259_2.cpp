#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N = 1000005;
int n, num, q[N], k, temp;

string str;

int main(){
    while(cin>>n && n ){
        queue<int> teamQ, Q[1005];
        cout<<"Scenario #"<<++num<<endl;
        for(int i = 1; i <= n; i++){
            cin>>k;
            while(k--){cin>>temp;q[temp] = i;}
        }
        while(cin>>str && str[0]!='S'){
            if(str[0] == 'E'){
                cin>>temp;
                if(Q[q[temp]].size()== 0)
                    teamQ.push(q[temp]);
                Q[ q[temp] ].push(temp);
            }
            else{
                cout<<Q[teamQ.front()].front()<<endl;
                Q[teamQ.front()].pop();
                if(Q[teamQ.front()].size()==0)teamQ.pop();
            }
        }
        cout<<endl;


    }
}
