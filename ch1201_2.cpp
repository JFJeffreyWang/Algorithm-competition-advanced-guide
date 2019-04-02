#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
deque<pair<int, int> > q;
const int N = 300008;
int n, m, a[N], b[N],ans = -0x3f3f3f3f, temp;
int main(){
    cin>>n>>m;
    memset(b,0x3f,sizeof(b));
    b[1] = 0;
    q.push_back(make_pair(0,0));
    for(int i = 1; i <= n; i++){
        cin>>temp;
        a[i] = a[i-1]+temp;
        while(q.front().first < i-m)q.pop_front();
        ans = max(ans, a[i]-q.front().second);
        while(q.size() && q.back().second>=a[i])q.pop_back();
        q.push_back(make_pair(i, a[i]));
    }
    cout<<ans;


}
