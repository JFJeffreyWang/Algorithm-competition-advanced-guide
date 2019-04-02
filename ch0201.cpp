#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char t[8];
bool a[8][8], b[8][8];
const int INF = 0x3f3f3f3f;
int n,ans = INF,c[8], v[5][2] = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0} };

bool nextC(int n){
    if(n == 0 && c[1] == 6) return 0;
    c[n+1] = 6;
    if(n == 0) return 1;
    if(c[1] == 0){
            for(int j = 1; j <= n ; j++){
                c[j] = j;
            }
    return 1;
    }
    int i = n;
    while(i){
       if( c[i]< c[i+1]-1){
            c[i]++;
            for(int j = i + 1; j <= n; j++){
                c[j] = c[j-1] + 1;
            }
            return 1;
        }
        i--;
    }
    return 0;

}

 void push(int x, int y){

    for( int i = 0; i < 5; i++){
        int nx = x + v[i][0], ny = y + v[i][1];
        b[nx][ny] = !b[nx][ny];

    }


}


int calc(){

    int cnt = 0;
    memcpy(b, a, sizeof(b));
    for(int i = 1; c[i] != 6; i++){
        push(1,c[i]);
        cnt++;
    }
    for(int i = 2; i <= 5; i++){
        for(int j = 1; j <= 5; j++)
            if(!b[i-1][j])push(i,j), cnt++;
    }
    for(int i = 1; i <= 5; i++)
        if(!b[5][i]) return -1;
    return cnt;



}

int main(){
    cin>>n;
    while(n--){
        ans = INF;
        for(int i = 1; i <= 5; i++){
        cin>>t+1;

            for(int j = 1; j <= 5;j++){
                a[i][j] = t[j]-'0';
            }
        }


        for(int i = 0; i <= 5 && i < ans; i++){
           c[1] = 0;
           while(nextC(i)){
                int temp = calc();
                if(temp >= 0 && temp<ans){
                    ans = temp;


                }
           }
        }

        if(ans == INF) ans = -1;
        cout<<ans<<endl;



    }


}
