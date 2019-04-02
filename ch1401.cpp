#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000005;
unsigned long long p[N], f[N];
char s[N];


int main(){
    cin>>s+1;
    int n, q;
    n = strlen(s+1);
    cin >> q;
    p[0] = 1;
    for(int i = 1; i<= n; i++){
        f[i] = f[i-1] * 131 + s[i]-'a';
        p[i] = p[i-1] * 131;
    }
    for(int i = 1; i<= q; i++){
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        if(f[r1] - f[l1-1]*p[r1-l1+1] == f[r2] - f[l2-1]*p[r2-l2+1])
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
