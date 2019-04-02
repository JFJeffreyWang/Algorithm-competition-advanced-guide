#include<iostream>
#include<queue>

using namespace std;
const int N = 15;
int n,order[N];
queue<int> Q;

void calc(int x){
    if(x == n+1){
        for(int i=1;i<=n;i++){
            cout<<order[i]<<' ';
        }
        cout<<endl;
    }
    for(int i = 1;i<=Q.size();i++){
        order[x] = Q.front();
        Q.pop();
        calc(x+1);
        Q.push(order[x]);
    }

}

int main(){
    cin>>n;
    for(int i=n;i>=1;i--){
        Q.push(i);
    }
    calc(1);

}
