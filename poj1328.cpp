#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int n , num = 0, l, r ;
double eps = 0.000001;
priority_queue<pair<double, double> > Q;
double x,y,d;
int main(){
    while(cin>>n>>d && (n && d) ){
        int ans = 0, t = 0x3f3f3f;
        for(int i = 1; i<=n; i++){
            cin>>x>>y;
            if(abs(y)>d+eps){
                    ans = -1;
                    priority_queue<pair<double,double> > emptyQ;
                    swap(Q,emptyQ);
                    break;
            }
            Q.push(make_pair(x-sqrt(d*d-y*y), x+sqrt(d*d-y*y)));
            //cout<<x-sqrt(d*d-y*y)<<endl;
        }
        while(Q.size()){
            if(Q.top().second<t+eps){
                ans++;
                t = Q.top().first;
            }
            Q.pop();
        }
        cout<<"Case "<<++num<<": "<<ans<<endl;
    }

}
