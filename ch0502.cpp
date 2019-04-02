#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100006;
int n, m, k, r[N], c[N],s[N];
long long cnt;

int main(){
    cin>>n >> m >>k;
    if(k % n && k % m) {cout <<"impossible" ; return 0;}
    if (k % m) cout << "row ";
    else if(k % n) cout << "column ";
    else cout<<"both ";
    int a, b;
    for(int i = 1; i <= k; i++){
        cin>>a>>b;
        r[a]++;
        c[b]++;
    }
    if(!(k % n) ) {
        int temp = k / n;
        for(int i = 1; i <= n; i++)r[i]-= temp , s[i] = s[i-1] + r[i];
        sort(s+1, s+n+1);
        for(int i = 1; i <= n/2; i++)cnt += s[n+1-i] - s[i];
    }

    if(!(k % m) ) {
        int temp = k / m;
        for(int i = 1; i <= m; i++)c[i]-= temp , s[i] = s[i-1] + c[i];
        sort(s+1, s+m+1);
        for(int i = 1; i <= m/2; i++)cnt += s[m+1-i] - s[i];
    }
    cout<<cnt;


}
