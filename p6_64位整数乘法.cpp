#include<iostream>
long long mul(long long a, long long b, long long p){
a %= p, b%= p;
long long c = (long double) a * b / p;
long long ans =  a * b - c * p;
if (ans < 0) ans += p;
else if (ans >= p) ans -= p;
return ans;
}
int main(){
    using namespace std;
    long long a,b,p;
    cout<<"input a b p"<<endl;
    cin>>a>>b>>p;
    cout<<mul(a,b,p)<<endl;
}
