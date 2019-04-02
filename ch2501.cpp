#include<iostream>
#include<queue>
using namespace std;

int a[1005][1005],b[1005][1005] ,n,m,v[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char c[1005];
queue<pair<int,int> > Q;

bool valid(int x, int y){
    return (x>=1 && x <= n && y >= 1 && y <= m);
}

int main(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>c+1;
        for(int j = 1; j <= m; j++){
            b[i][j] = c[j]-'0';
            if(b[i][j]){
                Q.push(make_pair(i,j));
            }
        }
    }

    while(Q.size()){
        int x = Q.front().first, y = Q.front().second;
        cout<<"test "<<x<< ' ' << y << endl;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+v[i][0], ny = y + v[i][1];
            if(!b[nx][ny] && valid(nx,ny)){
                a[nx][ny] = a[x][y] + 1;
                b[nx][ny] = 1;
                Q.push(make_pair(nx,ny));
            }
        }

    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= m; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }

}
