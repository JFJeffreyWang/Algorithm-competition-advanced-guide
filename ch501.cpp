#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100005;
int n,a[N];

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin>>a[i];
    sort((a+1), (a+n+1));
    int sum = 0;
    for(int i = 1; i <= (n>>1); i++){
        sum+=a[n-i+1] - a[i];
    }
    if(n&1) sum += a[(n>>1)+1];
    cout<<sum;
    return 0;
}
