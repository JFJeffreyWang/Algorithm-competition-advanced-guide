#include<iostream>
#include<cstring>
using namespace std;
char c[6];
bool s[7][7];



void an(bool s[][7],int x,int y){
  //  cout<<x<<' '<<y<<endl;
    s[x][y]=(s[x][y])?0:1;
    s[x+1][y]=(s[x+1][y])?0:1;
    s[x-1][y]=(s[x-1][y])?0:1;
    s[x][y+1]=(s[x][y+1])?0:1;
    s[x][y-1]=(s[x][y-1])?0:1;
}


int solve(){
    bool te[7][7];


    int ans=0,reans=0x3f3f3f;
    for(int ii=0;ii<32;ii++){
           // cout<<ii<<endl;

        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                te[i][j]=s[i][j];
            }
        }
        ans=0;
        for(int j=1;j<=5;j++){
            if(ii>>(j-1) & 1) {
                an(te,1,j);
                ans++;
            }
        }
        for(int k=2;k<=5;k++){
            for(int l=1;l<=5;l++){
                if(te[k-1][l]==0){
                    an(te,k,l);
                    ans++;
                }
            }
        }
        if(te[5][1] && te[5][2] && te[5][3] && te[5][4] && te[5][5]){
            if (ans<reans)reans=ans;

        }

      //  cout<<endl;

    }
    return (reans<=6)?reans:-1;
}


int main(){
    int n;
    int da;
    cin>>n;
    while(n--){
        for(int i = 1;i <= 5; i++){
            cin>> c;
            for(int j = 1;j<=5;j++){
                s[i][j]=(c[j-1]=='0')?0:1;
            }
        }

        cout<<solve()<<endl;
    }

}
