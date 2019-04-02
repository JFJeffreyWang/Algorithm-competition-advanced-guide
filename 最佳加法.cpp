#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll has[55];
int m;
ll f[55];

ll kp(int a, int b){
   ll ans = 1;
   while(b){
        if(b&1) ans *=a;
        a*=a;
        b>>=1;
   }
   return ans;
}
int main(){
    while(cin>>m){

        cin>>has[1];
        int n;
        for(n = 1; has[n]; n++){
            has[n+1] = has[n]/10;
        }
        n--;
        reverse(has+1, has+n+1);
        memset(f,0x3f,sizeof(f));
        f[0] = 0;
        m++;
        for(int i = 1; i <= m; i++){
            for(int j = n-m+i; j >= i; j--){
                for(int k = i-1; k <=j-1; k++)
                    f[j] = min(f[j], f[k] + has[j] - has[k]*kp(10,j-k));
            }
        }
        cout<<f[n]<<endl;

    }

}

