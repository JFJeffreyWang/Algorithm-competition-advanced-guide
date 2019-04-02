
#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N = 100005;
int n, m, t, x[N], y[N], a[N], s[N];;
int main(){
    cin>>n >> m >> t;
    for(int i = 1; i <= t; i++) {
        cin<<x[i];
        cin<<y[i];
    }
    bool row = !(t % n), column = !(t % m);
    if(row && colunm)cout<<"both ";
    else if(row) cout<<"row ";
    else if(column) cout << "column ";
    else {
        cout<<"impossible"<<endl;
        return 0;
    }

    ll ans = 0;
    if(row){
        int num = t / n;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= t; i++)a[x[i]]++;
        for(int i = 1; i <= t; i++)a[i] -= num;
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
        sort(s + 1, s + n + 1);
        for(int i = 1; i <= n/2; i++) ans += s[n-i+1] - s[i];

    }




}
