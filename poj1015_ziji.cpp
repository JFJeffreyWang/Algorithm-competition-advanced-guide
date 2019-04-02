#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 205;
int f[25][805],  n, m, a[N], b[N];



int main(){
    while(cin >> n >> m &&n){
    memset(f, 0xcf, sizeof(f));
    f[0][400] = 0;
    for(int i = 1; i <= n; i++){
            cin>>a[i]>>b[i];
        for(int k = 1; k <=m; k++ )
        for(int j = 800; j - a[i]+b[i]>=0 ; j--){
            if( f[k-1][j-a[i]+b[i] ]+a[i]+b[i]>0 && f[k-1][j-a[i]+b[i] ]+a[i]+b[i]>=f[k[j]){


            }
            f[k][j] = max(f[k][j], f[k-1][j-a[i]+b[i] ]+a[i]+b[i]);
            //cout<<"f " << k << ' ' << j << ' ' << f[k][j]<<endl;
            }
        }
    }

    for(int i = 0; i <=400; i++){

        if(f[m][400-i]>0 && f[m][400-i]>f[m][400+i]){
                cout<<(f[m][400-i]-i)/2 <<" "<< (f[m][400-i]+i)/2<<endl;
                break;
            }
        if(f[m][400+i]>0 && f[m][400+i]>=f[m][400-i]){
            cout<<(f[m][400-i]+i)/2 <<" "<< (f[m][400-i]-i)/2 << endl;
            break;
        }
    }
    }


}
