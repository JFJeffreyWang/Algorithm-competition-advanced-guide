#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 53;
int n, m, a[N][N], f[N<<1][N][N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    f[1][1][2] = a[1][2]+a[2][1]+a[1][1];
    for(int i = 1; i < n + m -2; i++){
        for(int j = 1; j <= n && j <=i+1;j++)
        for(int k = j+1; k <= n && k <= i+1; k++){
            f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k] + a[j][i+3-j] + a[k][i+3-k]);
            f[i+1][j+1][k+1] = max(f[i+1][j+1][k+1], f[i][j][k] + a[j+1][i+2-j] + a[k+1][i+2-k]);
            f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k] + a[j][i+3-j] + a[k+1][i+2-k]);
            if(k == j+1) f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k]+a[k][i+3-k]) ;
            else f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k] + a[j+1][i+2-j] + a[k][i+3-k]);
        }
    }
    cout<<f[n+m-2][n][n] << endl;

}
