#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int c[20],cab[20],n,w,ans;

void dfs(int now, int cnt){
    if(cnt >= ans) return;
    if(now == n+1){
        ans = min(ans,cnt);
        return;
    }
    for(int i = 1; i <= cnt; i++){
        if(cab[i] + c[now] <= w){
            cab[i] += c[now];
            dfs(now+1, cnt);
            cab[i] -= c[now];
        }
    }
    cab[cnt+1] = c[now];
    dfs(now+1, cnt+1);
    cab[cnt+1] = 0;
}

int main(){
    cin >> n >> w;
    for(int i = 1; i<=n; i++)cin>>c[i];
    sort(c+1, c+n+1);
    reverse(c+1, c+n+1);
    ans = n;
    dfs(1,0);
    cout<<ans << endl;
}
