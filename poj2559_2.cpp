#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int N = 100006;
int n, a[N];
stack<pair<int, int> > S;

int main(){
    while(cin>>n && n){
        long long ans= 0;
        for(int i = 1; i <= n; i++)cin>>a[i];
        a[n+1] = 0;
        for(int i = 1; i <= n+1; i++){
            int cnt = 0;
            while(S.size() && a[i]<=S.top().first){
                cnt+=S.top().second;
                ans = max(ans, (long long)S.top().first * cnt);
                S.pop();
            }
            S.push(make_pair(a[i], cnt+1 ));
        }
        cout<<ans<<endl;
    }
}
