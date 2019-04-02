#include<iostream>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
const int N = 30010;
int n, m, deg[N], a[N];
int ver[N], Next[N], head[N], tot, cnt;
bitset<N> f[N];

void add(int x, int y){
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
    deg[y]++;
}
void topsort(){
    queue<int> q;
    for(int i = 1; i<= n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(q.size()){
        int x = q.front();q.pop();
        a[++cnt] = x;
        for(int i = head[x]; i; i = Next[i]){
            int y = ver[i];
            if(--deg[y] == 0)q.push(y);
        }
    }
}

void calc(){
    for(int i = cnt; i; i--){
        int x = a[i];
        f[x][x] = 1;
        for(int i = head[x]; i; i = Next[i]){
            int y = ver[i];
            f[x] |= f[y];
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    topsort();
    calc();
    for(int i = 1; i <= n; i++)cout<<f[i].count()<<endl;
}
