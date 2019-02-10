#include<iostream>
#include<bitset>
int main(){
    using namespace std;
    long long a,b,c;
    int k;
    //cin>>a>>k;
    a=13434232;
    k=10;
    cout<<bitset<sizeof(a)*8>(a)<<endl;
    cout<<"a       "<<a<<"     k      "<<k<<endl;
    cout<<"the"<<k<<"th num    "<<((a>>k)&1)<<endl;
    cout<<bitset<sizeof(a)*8>(a&((1<<k)-1))<<endl;
    cout<<bitset<sizeof(a)*8>(a ^ (1<<k) )<<endl;
}
