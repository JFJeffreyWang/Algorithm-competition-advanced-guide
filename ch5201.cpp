#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 105, M = 10005;
int f[M],n, m,a[N];

int main(){
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        for(int j = m; j>=a[i]; j--){
            f[j] += f[j-a[i] ];
        }
    }
    cout << f[m] << endl;
}
