#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>


using namespace std;

struct rec{int x, y, lie;};
char s[510][510];
rec st, ed;
int n, m, d[510][510][3];
queue<rec> q;
bool valid(int x, int y){return x>=1 && y>=1 && x<=n && y<=m;}
const int dx[4] = {0,0,-1,1},dy[4]={-1,1,0,0};

void parse_st_ed(){
    for(int i = 1; i<=n; i++)
        for(int j = 1;j <= m; j++)
            if (s[i][j] == 'O'){
                ed.x = i,ed.y=j,ed.lie=0,s[i][j] = '.';
            }
            else if (s[i][j] == 'X'){
                for(int k = 0;k < 4;k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(valid(x,y) && s[x][y] == 'X'){
                        st.x = min(i,x),st.y = min(j,y),st.lie = k<2?1:2;
                        s[i][j]=s[x][y]='.';
                        break;
                    }
                }
                if ( s[i][j] == 'X'){
                    st.x = i,st.y = j, st.lie = 0;
                }
            }

}

bool valid(rec next){
    if(!valid(next.x ,next.y))return 0;
    if(s[next.x][next.y] == '#')return 0;
    if(next.lie == 0 && s[next.x][next.y] != '.')return 0;
    if(next.lie == 1 && s[next.x][next.y + 1] == '#') return 0;
    if(next.lie == 2 && s[next.x + 1][next.y] == '#') return 0;
    return 1;
}
const int next_x[3][4] = {{0,0,-2,1},{0,0,-1,1},{0,0,-1,2}};
const int next_y[3][4] = {{-2,1,0,0},{-1,2,0,0},{-1,1,0,0}};
const int next_lie[3][4] = {{1,1,2,2},{0,0,1,1},{2,2,0,0}};

int bfs(){
    for (int i = 1; i <= n; i++)
        for(int j = 1;j <= m; j++)
            for(int k = 0;k < 3;k++) d[i][j][k] = -1;
    while (q.size())q.pop();
    d[st.x][st.y][st.lie] = 0;
    q.push(st);
    while(q.size()){
        rec now = q.front();q.pop();
        for(int i = 0; i<4;i++){
            rec next;
            next.x = now.x + next_x[now.lie][i];
            next.y = now.y + next_y[now.lie][i];
            next.lie = next_lie[now.lie][i];
            if(!valid(next))continue;
            if(d[next.x][next.y][next.lie] == -1){
                d[next.x][next.y][next.lie] = d[now.x][now.y][now.lie] + 1;
                q.push(next);
                if(next.x == ed.x && next.y == ed.y && next.lie == ed.lie)
                    return d[next.x][next.y][next.lie];
            }
        }

    }
    return -1;
}


int main(){
    while(cin >> n >> m && n){
        for(int i = 1; i<= n; i++) scanf("%s", s[i] + 1);
        parse_st_ed();
        int ans = bfs();
        if(ans == -1) puts("Impossible");else cout << ans <<endl;
    }
}
