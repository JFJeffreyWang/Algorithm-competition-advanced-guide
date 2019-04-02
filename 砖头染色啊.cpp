#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, a[19][19], b[19][19], mans = 0x3f3f3f3f, s[19],ns;
char temp[19];


bool nexts(){
    if(ns ==-1){
        ns =0;
        return 1;
    }
    int i = ns;
    s[ns+1] = n+1;
    while(i>0){
        if(s[i]+1<s[i+1]){
            s[i]++;
            for(int j = i+1; j <= ns; j++){
                s[j] = s[j-1]+1;
            }
            return 1;
        }
        else{
            i--;
        }
    }
    if(ns==n)return 0;
    ns++;
    for(int i =1; i <= ns; i++)s[i] = i;
    return 1;
}

void an(int x, int y){
    b[x][y]= !b[x][y];
    b[x+1][y] = !b[x+1][y];
    b[x-1][y] = !b[x-1][y];
    b[x][y+1] = !b[x][y+1];
    b[x][y-1] = !b[x][y-1];

}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>temp+1;
        for(int j =1; j <= n; j++){
            if(temp[j]=='y')a[i][j]=1;
            else a[i][j] =0;
        }

    }

    ns = -1;
    while(nexts() && ns<mans){
        memcpy(b,a,sizeof(b));
        int ans = 0;
        for(int i = 1; i <= ns; i++){
            an(1, s[i]);
            ans++;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= n; j++){
            if(!b[i-1][j]){
                an(i,j);
                ans++;
            }
            }
        }
        if(ans>=mans)continue;
        int flag = 0;
        for(int i = 1; i <= n; i++){
            if(!b[n][i]){
                flag = 1;
                break;
            }
        }
        if(flag)continue;
        mans = ans;
    }
    if(mans==0x3f3f3f3f)cout<<"inf";
    else cout<<mans;


}
