#include<iostream>
#include<algorithm>
using namespace std;

int a[50], n;
long long w, ans = 0, s[50];
void dfs(int x, long long cab ){
    //cout<<"test" << x<<' '<<cab<<endl;
    if(cab >= w)return;
    if(cab>ans) {ans = cab; }
    if(x>n)return;
    if(cab + s[x]<=ans) return;
    dfs(x+1, cab+a[x]);
    dfs(x+1, cab);



}


int main(){
    cin>>w>>n;
    int temp;
    for(int i = 1; i<= n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    for(int i = n; i; i--)s[i] =s[i+1]+a[i];
    dfs(1,0);
    cout<<ans;
}
