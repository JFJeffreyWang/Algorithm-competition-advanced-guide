#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 100006;
int n, m;
double a[N], b[N], s[N];
double EPS = 1e-5, MAX = 1e6;


double calc(double l, double mid, double r){
    if(r-l<EPS) return r;
    s[0] = 0;
    for(int i = 1; i<= n; i++) b[i] = a[i]-mid;
    for(int i =1; i <= n; i++) s[i] = s[i-1] + b[i];
    double Min = 1e10, Max = -1e10;
    for(int i = m; i <= n; i++ ){
        Min = min(Min, s[i-m]);
        Max = max(Max, s[i] - Min);
    }
    if(Max>=0) return calc(mid, (mid+r)/2, r);
    return calc(l, (l+mid)/2, mid);



}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin>>a[i];
    cout<< int(calc(-MAX, 0, MAX)*1000 );

}
