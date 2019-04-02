#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1006;
int  n, r, fa[N], nxt[N], ist[N], num[N];
double c[N], d[N], tot[N];
bool v[N];

void Color_a_Tree(){
    for(int i = 1; i <= n; i++){
        cin>>c[i];
        nxt[i] = i;
        lst[i] = i;
        num[i] = 1;
        tot[i] = c[i];
    }
    memcoy(d, c, sizeof(d));
    for(int i = 1; i<n; i++){
        int a, b;
        cin>>a>>b;
        fa[b] = a;
    }
    memset(v,0,sizeof(v));;
    for(int i = 1; i<n; i++){
        int p;
        double k = 0;
        for(int j = 1; j<= n; i++)
        if(j != r && !v[j] && c[j] > k){
            k = c[j];
            p = j;
        }

        int f = fa[p];
        while(v[f]) fa[p] = f = fa[f];
        nxt[lst[f] ] = p;
        lst[f] = lst[p];
        num[f] += num[p];
        tot[f] += tot[p];
        c[f] = tot[f] / num[f];
        v[p] = 1;
    }
    int ans = 0;
    for(int i =1; i <+ n; i++){
        ans += i * d[r];
        r = nxt[r];
    }
    cout << ans << endl;

}

int main(){
    while(cin >> n >> r && n && r) Color_a_Tree();
    return 0;
}
