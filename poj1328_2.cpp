#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int n;
double EPS = 1e-7, d;


int main(){
    int cnt = 0;
    int a, b;
    while(cin>>n>>d && n){
            cnt++;
        double now = 1e10;
        int ans=  0;
        bool flag  = 0;

        pair<double, double >  Q[1006];
        memset(Q,0,sizeof(Q));
        for(int i = 1; i <= n; i++){
            cin>>a>>b;
            if(b>d+EPS){
            flag = 1;
            continue;
            }
            double r = a + sqrt((long double)d*d - (long double)b*b);
            double l = a - sqrt((long double)d*d - (long double)b*b);
            Q[i] = make_pair(l,r);
        }
        if(flag){cout << "Case " << cnt << ": " << -1 << endl;continue;}
        sort(Q+1,Q+n+1);
        reverse(Q+1,Q+n+1);
        for(int i = 1; i <=n; i++){
            if(Q[i].second >= now-EPS)continue;
            now = Q[i].first;
            ans++;
        }

        cout << "Case " << cnt<< ": " << ans << endl;

    }
}

