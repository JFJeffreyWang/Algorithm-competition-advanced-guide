#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
set<int> S,S2;
vector<int> V;
int a[50], n, m,ans,w;
long long  s[50];
void dfs1(int x, long long cab ){
    //cout<<"test" << x<<' '<<cab<<endl;
    if(cab >= w)return;
    if(x>n){
            S.insert(cab);
            return;
    }
    dfs1(x+1, cab+a[x]);
    dfs1(x+1, cab);

}

void dfs2(int x, long long cab ){
    //cout<<"test" << x<<' '<<cab<<endl;
    if(cab >= w)return;
    if(x>m-1){
            S2.insert(cab);
            return;
    }
    dfs2(x+1, cab+a[x]);
    dfs2(x+1, cab);

}


int main(){
    cin>>w>>n;
    int temp;
    for(int i = 1; i<= n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    m =(1+n)>>1;

    for(int i = n; i>=m; i--)s[i] =s[i+1]+a[i];
    s[m-1] = a[m-1];
    for(int i = m-2; i; i--)s[i] = s[i+1] + a[i];
    dfs1(m, 0);
    dfs2(1,0);
    cout<<S.size()<<' '<<S2.size()<<endl;
    set<int> :: iterator ite = S2.begin(), tie;
    for(; ite!=S2.end();ite++){
        tie =S.upper_bound(w-*ite);
        if(!(tie==S.begin())){
            ans = max(ans, *ite + *(--tie));
        }

    }
    cout<<ans;

}
