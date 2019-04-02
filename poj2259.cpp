#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 1000005;
queue<int> Q[1005];
string s;
int n,m,q[N],t;


int calc(int num){
    cout<<"Scenario #"<<num<<endl;
    queue<int> Qe[1005];
    swap(Qe,Q);
    for(int i = 1; i<= n; i++){
        cin>>m;
        for(int j = 1; j<= m; j++){
            cin>>t;
            q[t] = i;
        }
    }
    while(cin>>s && s != "STOP"){
        if(s=="ENQUEUE"){
            cin>>t;
            if(!Q[q[t]].size())Q[0].push(q[t]);
            Q[q[t]].push(t);

        }
        else if(s=="DEQUEUE"){
            cout<<Q[Q[0].front()].front()<<endl;
            Q[Q[0].front()].pop();
            if(!Q[Q[0].front()].size()) Q[0].pop();
        }

    }
    cout<<endl;


}

int main(){
    int num = 1;
    while(cin>>n && n) calc(num++);


}
