#include<iostream>
#include<bitset>
int main(){
    using namespace std;
    long long a=23423435264;
    cout<<bitset<sizeof(a) * 8>(a)<<endl;
    cout<<bitset<sizeof(a) * 8>(a&(-a))<<endl;

}

