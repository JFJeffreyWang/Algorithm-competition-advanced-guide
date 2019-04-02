#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, w[22][22],f[1<<20][20];

int calc(){
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < 1<<(n-1); i++){
        for(int j = 1; j < n; j++) if( !(i>>j & 1) ) {
            for(int k = 0; k < n; k++) if( i>>k & 1 ){
                f[i][j] = min(f[i][j], f[ i ^ 1<<k][k] + w[k][j]);
               // if(f[i][j]<100)cout<<"test"<< i<<' '<<j << ' ' << f[i][j]<<endl;
            }
        }
    }

    return f[(1<<(n-1))-1][n-1];
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j++)
        cin>>w[i][j];
    cout<<calc();
}
