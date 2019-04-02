#include<iostream>

using namespace std;
const int N = 106;
int ans[N], n,dep;

bool dfs(int x){
    int num;
    if(x == dep)return (ans[x] == n) ;
    for(int i = x; i; i--){
        for(int j = i; j; j--){
            num = ans[i] + ans[j];
            if(num > ans[x] && num <= n){
                ans[x+1] = num;
                if(dfs(x+1))return 1;
            }
        }
    }
    return 0;
}

int main(){
    ans[1] = 1;
    while(cin>>n && n){
        dep = 1;
        while(!dfs(1))dep++;
        for(int i = 1; i <= dep; i++)cout<<ans[i]<<' ';
        cout<<endl;
    }
}
