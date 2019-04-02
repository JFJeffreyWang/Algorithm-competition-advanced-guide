//Autor WJF ´ð°¸´íÎó

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>


using namespace std;
const int N=1005;
vector<pair<int,int> > v[N];
int n,m,st,ed,k;
priority_queue<pair<int,int> > Q;

int main(){
    int a,b,c;
    cin>>n>>m;
        priority_queue<pair<int,int> > empty;
        swap(Q,empty);
        memset(v,0,sizeof(v));
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            v[a].push_back(make_pair(b,c));
           // vb[b].push_back(make_pair(a,c));
        }
        cin>>st>>ed>>k;
        Q.push(make_pair(0,st));
        while(true){
            a=-Q.top().first;
            b=Q.top().second;
            Q.pop();
            if(b==ed){
                k--;
                if(k==0){
                    cout<<a;
                    break;
                }
            }
            int vs = v[b].size();
            for(int i=0;i<vs;i++){
                Q.push(make_pair(-a-v[b][i].second,v[b][i].first));
            }
        }






}
