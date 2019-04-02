#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100005;
int n,L;
double a[N],b[N];

int main(){
    cin>>n >> L;
    for(int i = 0;i<=n;i++){
        cin>>a[i];
    }

    double eps = 1e-5,l = 0,r = 3000,sum[N];
    while(r - l > eps){
        double mid = (r - 1)/2;
        for(int i = 0;i<=n;i++){
            b[i] = a[i]-mid;
            sum[i] = sum[i-1] + b[i];
        }
        double min_val = 1e10;
        double ans = -1e10;
        for(int i = L;i<=n;i++){
            min_val = min(min_val,sum[i - L]);
            ans = max(ans,sum[i]-min_val);
        }
        if(ans>0)l = mid;else r = mid;
    }
}
