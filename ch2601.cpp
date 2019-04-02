#include<iostream>
#include<deque>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 506;
int r,c,vi[4][2] = {{-1,-1},{-1,1},{1,1},{1,-1}}, v[N][N];
char a[N][N];
bool lu[N][N][4];
deque<pair<int,int> > Q;

void calc(){
    cin>>r>>c;

    for(int i = 1; i <= r; i++){
        cin>>a[i]+1;
    }
    if((r&1)!= (c&1)) {
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    memset(lu,0,sizeof(lu));
     for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(a[i][j]== '/'){
                lu[i][j-1][1] = 1;
                lu[i-1][j][3] = 1;
            }
            else{
                lu[i-1][j-1][2] =  1;
                lu[i][j][0] = 1;
            }
        }
    }

    memset(v,0x3f,sizeof(v));

    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
                printf("%2d ",v[i][j]%91);
        }
        cout<<endl;
    }
    cout<<endl;

    Q.clear();
    Q.push_back(make_pair(0,0));
    v[0][0] = 0;
    while(Q.size()){
        int x = Q.front().first, y = Q.front().second;
        Q.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = x + vi[i][0];
            int ny = y + vi[i][1];
            if(nx<0 || ny<0 ||nx>r || ny > c)continue;
            if(lu[x][y][i]){
                if(v[nx][ny] > v[x][y]){
                    v[nx][ny] = v[x][y];
                    Q.push_front(make_pair(nx,ny));
                }
            }
            else{
                if(v[nx][ny] > v[x][y]+1){
                    v[nx][ny] = v[x][y]+1;
                    Q.push_back(make_pair(nx,ny));
                }
            }
        }
    }
    cout<<v[r][c]<<endl;

    cout<<"test : "<<endl;
    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
                printf("%2d ",v[i][j]%91);
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        calc();
    }
}
