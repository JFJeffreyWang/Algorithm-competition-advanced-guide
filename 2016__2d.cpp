#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define mp make_pair
int n, m;
bool v[10],r[10],c[10];
char temp[10];
vector<pair<int,int> > V;


int calc(int x, int kc){
    if(kc==m)return 1;
    if(x==V.size()+1)return 0;
    int ans = 0;
    if(n-x >= m-kc) ans += calc(x+1, kc);
    if( !r[V[x-1].first] && !c[V[x-1].second ] ) {
        r[V[x-1].first]=1, c[V[x-1].second] = 1;
        ans+=calc(x+1,kc+1);
        r[V[x-1].first]=0, c[V[x-1].second] = 0;
    }
    return ans;
}


int main(){
    while(cin>>n>>m && n != -1){
        V.clear();
        memset(v,0,sizeof(v));
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        for(int i = 1; i <= n; i++){
               cin>>temp+1;
        for(int j = 1; j <= n; j++){
            if(temp[j]=='#') V.push_back(mp(i,j));
        }

        }


        cout<<calc(1,0)<<endl;
    }

}
