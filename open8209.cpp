#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10006;
int f[N], n, m,a[N];
long long b[N];

int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
            cin>>a[i];
    }
    for(int i = 1; i<=n; i++){
        b[i] = b[i-1] + a[i];
    }

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = n-m+i; j >=i; j-- ){
            for(int k = i-1; k <= j-1;k++ )
                f[j] = min(f[j], max(f[k],(int)(b[j]-b[k]) ) );
        }

    }
    cout<<f[n];
}
