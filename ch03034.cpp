#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100006;
int n, a[N],s[N];
long long p, q;

int main(){
    cin>>n;
    for(int i = 1; i<= n; i++)cin>>a[i];
    for(int i = 2; i <= n; i++) {
        s[i] = a[i]-a[i-1];
        if(s[i]>0) p += s[i];
        else q -= s[i];
    }
    cout<<max(p,q) << endl << abs(p-q)+1;



}
