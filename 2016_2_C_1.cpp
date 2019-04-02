#include<iostream>
using namespace std;
const int N = 23;
int n, m, fx[4][2] ={{-1,0},{1,0},{0,-1},{0,1} }, f ;
string s,ans;
bool v[N][N];
char a[N][N];

void make(int x, int y){
    int i = 4;
    char st[5];
    for(int i = 0; i<5; i++)st[i] = '0';
    while(y && i >= 0){
        if(y&1) st[i] = '1';
        else st[i] = '0';
        y>>=1;
        i--;
    }
    for(int i = 0; i <5; i++){
        ans +=st[i];
    }
}

bool valid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && !v[x][y];
}

int main(){
    cin>>n>>m;
    getline(cin,s);
    for(int i = n+1-s.size()+1; i <= n; i++){
        int temp;
        if(s[i-n+s.size()-1]>='A' && s[i-n+s.size()-1] <= 'Z') temp = s[i-n+s.size()-1]-'A'+1;
        else temp = 0;
    //    cout<<"temp "<<temp<<endl;
        make(i,temp);
    }
    //cout<<ans<<endl;
    int x = 1,  y = 0;
    f = 3;
    for(int i = 0; i < n*m;){
        int nx = x + fx[f][0], ny = y + fx[f][1];
        if(valid(nx,ny)){
            v[nx][ny] = 1;
            if(i<ans.size()){a[nx][ny] = ans[i];}
            else {a[nx][ny] = '0';}
            i++;
            x = nx, y = ny;
        }
        else{
            f = (1+f)%4;
        }

    }
    for(int i =1; i <= n;i++){
        for(int j = 1; j <= m;j++){
            cout<<a[i][j];
        }
    }





}

