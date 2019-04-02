#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long f[4005];
int n;

int main(){
    cin >> n;
    f[0] = 1;
    for(int i = 1; i <= n-1; i++){
        for(int j = i; j <= n;j++){
            (f[j] += f[j-i])%=2147483648;
        }
    }
    cout << f[n];

}
