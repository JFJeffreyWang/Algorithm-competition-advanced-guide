#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 22;
int  r,c;
char a[N][N],lu[N*N],nc[5] = {'0','S','N','E', 'W'};
//priority_queue<stat> Q;
int v[5][2]={{0,0},{-1,0}, {1,0},{0,-1},{0,1}},lenlu, nv[5]{0,2,1,4,3};
priority_queue< pair<int,int> > Qlu;



bool valid(int x, int y, int x2, int y2){
    return ( x >=1 && x << r && y >= 1 && y <= c && a[x][y] != '#' && !(x==x2 && y == y2) );
}

bool run(int x1, int y1, int x2, int y2,int x3, int y3){
    if(!valid(x1,y1,x3,y3) || !valid(x2,y2,x3,y3)) return 0;

    int v[N][N];
    memset(v, 0, sizeof(v));
    while(Qlu.size())Qlu.pop();
    Qlu.push(make_pair(x1,y1));
    bool flag = 0;
    while(Qlu.size() && !flag){
        int x = Qlu.top().first, y = Qlu.top().second;
        Qlu.pop();
        for(int i = 1; i <= 4; i++){
            int nx = x + v[i][0], ny = y = v[i][1];
            if(valid(nx,ny,x3,y3) && v[nx][ny] == 0){
                v[nx][ny] = nv[i];
                if(nx==x2 && ny == y2){
                    flag = 1;
                    break;
                }
                Qlu.push(make_pair(nx, ny));

            }

        }

    }
    if(!flag)return 0;
    lenlu = 0;
    while(!(x2==x1 && y2 == y1 )){
        lu[++lenlu] = nc[v[x2][y2] ];
        x2 += v[v[x2][y2]][0];
        y2 += v[v[x2][y2]][1];
    }
    reverse(lu+1, lu+lenlu+1 );
}

//stat push(stat s, int i){

//}

void solve(){
    while(Q.size()){


    }

}

int main(){
    while(cin>>r>>c && r ){
        for(int i = 1; i <= r; i++)cin>>a[i]+1;

        solve();

    }

}
