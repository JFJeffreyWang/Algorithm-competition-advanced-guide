#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool v[105][105];
int n,m,a[105][105], fx, fxs[5][2] = {{0,0},{-1,0},{1,0},{0,-1},{0,1} }, cnt;
bool valid(int x, int y){
    return x>=1 && x <= n && y >= 1 && y <= m && v[x][y]==0;
}

int main(){
    cin>>n>>m;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j<=m; j++)
            cin>>a[i][j];

    fx = 4;
    int x= 1, y = 0,nx,ny;
    while(cnt<n*m){
        nx = x + fxs[fx][0];
        ny = y + fxs[fx][1];
       // cout<<nx<<' '<<ny<<endl;
        if(valid(nx,ny)){
            cout<<a[nx][ny]<<endl;
            v[nx][ny] = 1;
            cnt++;
            x = nx;
            y = ny;
        }
        else{
            for(int i = 1; i <= 4; i++){
                nx = x + fxs[i][0];
                ny = y + fxs[i][1];
                if(valid(nx,ny)){
                    fx = i;
                    break;
                }
            }
        }
    }

}
