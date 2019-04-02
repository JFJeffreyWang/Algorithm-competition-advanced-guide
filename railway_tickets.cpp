#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 10005;
#define ll long long
ll d[4], val[4], n, lsta, rsta, f[N], a[N];

inline ll dis(int l, int r){
    return a[r] - a[l];
}
int main(){
    while(cin>>d[1]>>d[2]>>d[3]>>val[1]>>val[2]>>val[3]>>n>>lsta>>rsta){
    for(int i = 2; i <= n; i++){
        cin>>a[i];
    }
    a[1] = 0;
    if(lsta>rsta)swap(lsta,rsta);
    memset(f,0x3f, sizeof(f));
    int i = lsta;
    f[lsta] = 0;
        for(int j = i+1; j <=rsta;j++){
            int tempi = j-1;

            while(tempi >=i && dis(tempi, j)<=d[1]){
               // cout<<"test"<<tempi << ' ' << j<<' ' <<f[j] << ' '<<f[tempi] + val[1];
                f[j] = min(f[j], f[tempi] + val[1]);
               // cout<<' '<<f[j]<<endl;
                tempi--;
            }
            while(tempi >=i && dis(tempi, j)<=d[2]){
               // cout<<"test"<<tempi << ' ' << j<<' ' <<f[j] << ' '<<f[tempi] + val[1];

                f[j] = min(f[j], f[tempi] + val[2]);
                //cout<<' '<<f[j]<<endl;
                tempi--;
            }
            while(tempi >=i && dis(tempi, j)<=d[3]){
               // cout<<"dis "<< dis(tempi, j)<<endl;
               // cout<<"test"<<tempi << ' ' << j<<' ' <<f[j] << ' '<<f[tempi] + val[1];

                f[j] = min(f[j], f[tempi] + val[3]);
               // cout<<' '<<f[j]<<endl;
                tempi--;
            }
        }

    cout<<f[rsta]<<endl;
    }

}
