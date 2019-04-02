#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100006;
int n, m;
double a[N], b[N], s[N];

bool isP(double x){
    for(int i = 1; i<= n; i++)b[i] = a[i] - x;
    s[0] = 0;
    for(int i = 1; i <=n; i++)s[i] = b[i] + s[i-1];

    double mm = 0, ans = 0;
    for(int i = m; i<= n; i++){
        mm = min(mm, s[i-m]);
        ans = max(ans, s[i] - mm);
    }
    if(ans>0)return 1;
    return 0;
}

void calc(){
    const double ep = 1e-6;
    double  l = 1e-10, r = 3000.0;
    while(r-l >ep){
        if(isP((l+r)/2)) l= (l+r)/2;
        else r = (l+r)/2;
    }
    cout<<(int)(r*1000)<<endl;
}

int main(){
    cin>>n >> m;
    for(int i = 1; i<= n; i++)cin>>a[i];
    calc();
}
