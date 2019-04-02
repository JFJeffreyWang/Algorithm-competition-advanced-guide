//Author WJF 自己写的
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 806;
int r,c,stx,sty,edx,edy,nmx1,nmx2,nmy1,nmy2;
char s[N][N];
queue<pair<int,int> > Qm, Qg;
bool v[N][N][2];
int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};


bool valid(int x, int y, int i){
    if(x < 1 || x > r)return 0;
    if(y < 1 || y > c)return 0;
    if(s[x][y] == 'X') return 0;
    if(abs(x - nmx1) + abs(y - nmy1) <= 2*i)return 0;
    if(abs(x - nmx2) + abs(y - nmy2) <= 2*i)return 0;
    return 1;

}


int bfs(){
    int nmflag = 0,mx,my,nx,ny;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(s[i][j] == 'M'){
                stx=i;
                sty=j;
                s[i][j] = '.';
            }
            else if(s[i][j] == 'G'){
                edx=i;
                edy=j;
                s[i][j] = '.';
            }
            else if(s[i][j] == 'Z'){
                if(nmflag == 0){
                    nmx1 = i;
                    nmy1 = j;
                }else{
                    nmx2 = i;
                    nmy2 = j;
                }
            }
        }
    }//地图初始化
    memset(v,0,sizeof(v));

    int day = 0;
    Qm.push(make_pair(stx,sty));
    Qg.push(make_pair(edx,edy));
    while(Qm.size() || Qg.size()){
        day++;
        if(Qm.size()){
        for(int j = 0;j < 3; j++){
            int qs = Qm.size();
            while( qs--){
                mx = Qm.front().first;
                my = Qm.front().second;
                Qm.pop();
                for(int i = 0; i< 4; i++){
                    nx = mx + fx[i][0];
                    ny = my + fx[i][1];
                    if(!v[nx][ny][0] && valid(nx,ny,day)){
                        Qm.push(make_pair(nx,ny));
                        v[nx][ny][0]=1;
                    }
                }
            }

        }
        }
        int qs = Qg.size();
        while(qs--){
            mx = Qg.front().first;
            my = Qg.front().second;
            Qg.pop();
            for(int i = 0; i< 4; i++){
                nx = mx + fx[i][0];
                ny = my + fx[i][1];
                if(!v[nx][ny][1] && valid(nx,ny,day)){
                    if(v[nx][ny][0]){
                        return day;
                    }
                    Qg.push(make_pair(nx,ny));
                    v[nx][ny][1]=1;
                }
            }

        }

    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>r,c;
        for(int i = 1;i <= r; i++){
            cin>>(s[i]+1);
        }
        cout<<bfs()<<endl;

    }

}
