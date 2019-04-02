#include<iostream>
#include<algorithm>
using namespace std;
int c[20], cab[20],n,w,ans=0x3f3f3f;

void dfs(int x,int cnt){
    if(cnt>=ans)return;
    if(x == n+1){
        ans = min(ans, cnt);
        return;
    }
    for(int i = 1; i<= cnt; i++){
        if(c[x]+cab[i]<=w){
            cab[i]+=c[x];
            dfs(x+1, cnt);
            cab[i]-=c[x];
        }
    }
    cab[++cnt] = c[x];
    dfs(x+1,cnt);
    cab[cnt] = 0;

}


int main(){
    cin>>n>>w;
    for(int i = 1; i<=n; i++)cin>>c[i];
    sort(c+1,c+n+1);
    reverse(c+1, c+n+1);
    dfs(1,0);
    cout<<ans;
}


