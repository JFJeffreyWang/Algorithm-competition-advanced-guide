#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 8;
bool a[N][N], b[N][N],c[N][N],ac[N][N];
int mans = 0x3f3f3f3f;


void an(int x, int y){
    c[x][y] = 1;
    b[x][y] = !b[x][y];
    b[x+1][y] = !b[x+1][y];
    b[x-1][y] = !b[x-1][y];
    b[x][y-1] = !b[x][y-1];
    b[x][y+1] = !b[x][y+1];
}

int main(){
    for(int i =1 ; i <= 5; i++)
        for(int j = 1; j <= 6; j++)
            cin>>a[i][j];

    for(int i = 0; i <= (1<<6)-1; i++){
        memcpy(b, a, sizeof(b));
        memset(c,0,sizeof(c));
        int cnt = 6;
        int ans = 0;
        int t = i;
        while(t){
            if(t&1){
                an(1,cnt);
                ans++;
            }
            t>>=1;
            cnt--;
        }
        for(int j = 2; j<=5 ; j++){
            for(int k = 1; k <= 6 ;k++ ){
                    if(b[j-1][k]){
                        an(j,k);
                        ans++;
                    }
            }
        }
        bool flag=0;
        for(int  j= 1; j <= 6; j++){
            if(b[5][j]){
                flag = 1;
                break;
            }
        }
        if(flag)continue;
        if(ans < mans){
            mans = ans;
            memcpy(ac, c, sizeof(c));
        }
    }

     for(int i =1 ; i <= 5; i++){
        for(int j = 1; j <= 6; j++)
            cout<<ac[i][j]<<' ';
        if(i <= 4)cout<<endl;
     }
}
