#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
#define mp make_pair
int n, m, fx[4][2] = {{0,-1},{-1,-1},{-1,0},{-1,1} };
const int N = 105;
pair<int ,int> T[N][N];
char a[N][N];
set<pair<int,int> > Se;


pair<int,int> root(int x, int y){
   // cout<<"root "<<x<<' '<<y<<endl;
    int ox = x, oy = y;
    int nx = T[x][y].first, ny = T[x][y].second;
    if(nx == 0 && ny == 0) return mp(0,0);
    stack<pair<int,int> > S;
    while(nx && ny && !(nx==x && ny == y) ){
        S.push(mp(x,y));
        x = nx;
        y = ny;
        nx = T[x][y].first, ny = T[x][y].second;
    }
    while(S.size()){
        T[S.top().first][S.top().second] = mp(x,y);
        S.pop();
    }
   // cout<<"out"<<endl;

    return mp(x,y);
}

void unin(int ax, int ay, int bx, int by){
   // cout<<"unin "<<ax <<' '<< ay<<' '<< bx<<' '<<by <<' '<<endl;
    pair<int,int> temp = root(bx,by);
    T[temp.first][temp.second] = root(ax, ay);
}

int main(){
    cin>>n>>m;
    char temp[N];
    for(int i = 1; i <= n; i++){
        cin>>(a[i]+1);
        for(int j = 1; j<=m; j++){
            if(a[i][j]=='W') {
                    T[i][j] = mp(i,j);
                    for(int k = 0; k <=3; k++){
                int nx = i + fx[k][0], ny = j + fx[k][1];
                if(a[nx][ny] == 'W'){
                    unin(nx,ny,i,j);
                }
            }

            }


        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=m; j++){
            if(T[i][j].first!=0){
                pair<int,int> temp = root(i,j);
               // cout<<"root "<<i<<' '<<j<<' '<<temp.first << ' ' << temp.second<<endl;
                Se.insert(temp);

            }
        }
    }
    cout<<Se.size();

}

