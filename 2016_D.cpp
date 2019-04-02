#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
int n, m, stx, sty, fx[5][2] = {{0,0},{-1,0},{1,0},{0,-1},{0,1} };
#define mp make_pair
using namespace std;
char a[22][22];
bool v[22][22];
int lu[22][22];
queue< pair<int, int> > Q;

bool valid(int x,int y){
    return x>=1 && x <= n && y >= 1 && y <= m && a[x][y] !='#';
}

int main(){
    while(cin>>n>>m && n){
        memset(v,0,sizeof(v));
        queue< pair<int, int> > eQ;
        swap(Q,eQ);
        bool flag = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>a[i][j];
                if(a[i][j]=='@'){
                    a[i][j] = '.';
                    stx = i;
                    sty = j;
                }
            }
        }

        Q.push(mp(stx,sty));
        v[stx ][sty] = 1;
        while(Q.size()){
            int x = Q.front().first, y = Q.front().second;
            Q.pop();
            if(a[x][y] == '*'){
                cout<<lu[x][y]<<endl;
                flag = 0;
            }
            for(int i = 1; i <= 4; i++){
                int nx = x + fx[i][0], ny = y + fx[i][1];
                if(valid(nx, ny) && !v[nx][ny]){
                    v[nx][ny] = 1;
                    lu[nx][ny] = 1 + lu[x][y];
                    Q.push(mp(nx,ny));
                }
            }
        }
        if(flag)cout<<-1<<endl;

    }



}
