#include<iostream>
#include<stack>
using namespace std;

#define ll long long
int ans = -0x3f3f3f;
const int N = 300005;
int n, m,a[N], s[N],Q[N],l,r ;

void calc(){
    for(int i = 1; i<=n; i++)cin>>a[i];
    for(int i = 1; i<=n; i++)s[i] = s[i-1]+a[i];
    r=l=1;
    Q[1] = 0;
    for(int i = 1; i<=n; i++){
        while(Q[l]<i-m && r>=l){
            l++;
        }
        ans = max(ans, s[i] - s[Q[l] ]);
        while(l<=r && s[Q[r]] >= s[i])r--;
        Q[++r] = s[i];
    }
    cout << ans << endl;
}


int main(){
    cin>>n>>m;
    calc();
}

