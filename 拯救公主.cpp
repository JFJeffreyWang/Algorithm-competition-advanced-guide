#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
#define mp make_pair

struct node{
    int s[5];
    node(int a,int b, int c, int d, int e){
        s[0]=a;
        s[1] = b;
        s[2]=c;
        s[3]=d;
        s[4]=e;
    }
};
char m[105][105];
bool v[105][105][12];
int  st[2], en[2], fx[5][2] = {{0,0},{-1,0},{1,0},{0,-1},{0,1} };
deque<node> Q;
int r,c,dc,ans,cnt;


bool valid(int x, int y){
    return (x >= 1 && x <= r && y >= 1 && y <= c  && m[x][y] != '#');
}

int main(){
    while(cin>>r>>c>>dc && r){

        for(int i = 1; i <= r; i++){
            cin>>(m[i]+1);
            for(int j = 1; j <= c;j++ ){
                if(m[i][j] == 'S'){st[0] = i;st[1] = j;m[i][j] = '.';}
                else if(m[i][j] == 'T')en[0] = i, en[1] = j, m[i][j] = '.';

            }
        }
        deque<node> Qe;
        swap(Q,Qe);
        Q.push_back( *(new node(st[0], st[1], 0, dc, 0)));
        v[st[0]][st[1] ][dc] = 1;
        ans = -1;
        while(Q.size()){
            int x=Q.front().s[0], y = Q.front().s[1];
            int ofx = Q.front().s[2], odc = Q.front().s[3], now = Q.front().s[4];
            Q.pop_front();

           // cout<<"test "<<x<<' '<<y<<' '<<ofx<<' '<<odc<<' '<<now<<endl;
            if(x == en[0] && y == en[1]){ans = now; break; }
            if(m[x][y] == 'E'){
                for(int i = 1; i <=odc; i++){
                    int nx = x+i * fx[ofx][0], ny = y+i * fx[ofx][1];
                    nx = (nx<=0)?1:nx;
                    nx = (nx>r)?r:nx;
                    ny = (ny<=0)?1:ny;
                    ny = (ny>c)?c:ny;
                    if(nx == x && ny == y) continue;
                    if(!valid(nx,ny) || v[nx][ny][i])continue;
                    if(m[nx][ny]=='.') v[nx][ny][i] = 1;
                    Q.push_front(*(new node(nx, ny, ofx, i, now)));
                }
            }
            for(int i = 1; i <= 4; i++){
                int nx = x+ fx[i][0] , ny = y+ fx[i][1] ;
                if(!valid(nx,ny) || v[nx][ny][odc])continue;
                if(m[nx][ny]=='.') v[nx][ny][odc] = 1;
                 Q.push_back(*(new node(nx, ny, i, odc, now+1)));
            }

        }
        cout<<"Case #"<<++cnt<<": "<<ans<<endl;


    }

}
