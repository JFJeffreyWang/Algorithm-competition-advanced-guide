#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 200006;
int n, s[N],e[N],d[N], maxe = -1, mins = 0x3f3f3f3f;

int calc(int x){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i]>x)continue;
        ans += (min(x, e[i])-s[i])/d[i]+1;
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>s[i]>>e[i]>>d[i];
            maxe = max(maxe, e[i]);
            mins = min(mins, s[i]);
        }
        if((calc(maxe) & 1) ==0){
            cout<<"There's no weakness."<<endl;
            continue;
        }
        int l = mins, r = maxe;
        while(l < r){
            int mid = (r+l)>>1;
            if(calc(mid) & 1){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        cout<<l<<' '<<calc(l)-calc(l-1)<<endl;
    }

}
