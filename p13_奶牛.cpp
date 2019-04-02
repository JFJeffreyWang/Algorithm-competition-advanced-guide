#include<iostream>
using namespace std;
int c[10010];
int main(){
    int n, p, h, m,a,b;
    cin >> n >> p >> h >> m;
    for(int i = 1; i<= n;i++){
        c[i]=h;
    }
    for(int i = 1;i<=m;i++){
        cin>>a>>b;
        int flag = 0;
        int mi = (a<b)?a:b;
        int ma = (a>b)?a:b;
        int mii = (c[mi]<c[ma])?c[mi]:c[ma];
        for(int j = mi+1;j<=ma-1;j++){
            if(c[j]==mii){
                flag=1;
                break;
            }
        }
        if(flag){
            for(int j = mi+1;j<=ma-1;j++){
                c[j]--;
            //    cout<< ' ' << j <<"--"<<endl;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<c[i]<<endl;
    }

}
