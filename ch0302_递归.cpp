#include<iostream>
#include<queue>
using namespace std;
bool a[30];
int n,m,q[30];
queue<int> Q;

void calc(int x, int b){
    if(x>m){
        for(int i = 1; i<= n; i++){
            cout<<q[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i = b; i<=n; i++){
        if(a[i])continue;
        a[i] = 1;
        q[x] = i;
        calc(x+1,1);
        a[i] = 0;

    }
}

int main(){
    cin>>n;
    m = n;
    calc(1,1);
}
