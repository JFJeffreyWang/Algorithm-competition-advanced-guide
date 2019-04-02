#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;µç×ÓÓÊ¼þ
int f[105][12];
const int INF = 0x3f3f3f3f;
int n, m;

int main(){
    while(cin>>n>>m){
    memset(f,0x3f,sizeof(f));
    for(int i = 0; i<=m; i++)f[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k=1; k <= i; k++)
            f[i][j] = min(f[i][j],max(1+f[k-1][j-1],1+f[i-k][j] ));
           // cout<<"f "<<i<<' '<<j<<' '<<f[i][j]<<endl;
        }
    }
    cout<<f[n][m]<<endl;
}
}
