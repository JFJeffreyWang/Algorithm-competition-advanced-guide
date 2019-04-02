#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int> Q;
vector<int> V;
int ans = 0x3f3f3f3f,n;

void dfs(){
    if(!Q.size()){
        if(V[0]>=ans)return;
        for(int i = 1; i < V.size(); i++){
            if(V[i] != V[0])return;
        }
        ans = V[0];
        //for(int i =0; i< V.size(); i++){
        //    cout<<V[i]<< ' ';
      //  }
    //    cout<<endl;
        return;
    }
    int temp = Q.top();
    Q.pop();

    for(int i = 0; i < V.size(); i++){
        if(V[i]+temp<ans){
            V[i]+=temp;
            dfs();
            V[i]-=temp;
        }
    }
    V.push_back(temp);
    dfs();
    V.erase(V.end()-1);
    Q.push(temp);
}


int main(){
    while(cin>>n && n){
            priority_queue<int> eQ;
        swap(eQ,Q);
        int temp;
        ans = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++){
                cin>>temp;
            Q.push(temp);
        }
        dfs();
        cout<<ans<<endl;
    }
}
