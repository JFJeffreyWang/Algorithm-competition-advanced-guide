#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
double  now,temp;
bool is;
int n;
double f[2][3];

double oo(double x){
    x*=100.0;
    int a = (int)x;
    return  a /100.0;
}

int main(){
    while(cin>>n && n){
        is = 1;
        f[0][0] = 1000.0;
        f[0][1] = 0;
        for(int i =1; i <= n; i++){
            cin>>temp;
            f[is][0] = max(f[!is][0], oo(f[!is][1] *temp * 0.97) );
            f[is][1] = max(f[!is][1], oo(f[!is][0] / temp * 0.97) );

        //    cout<<is <<' '<<  f[is][0] <<' '<< f[is][1]<<endl;
            is = !is;

        }
        //cout<<"test "<< (n&1);
        printf ( "%.2lf\n",f[n&1][0]);

    }
}
