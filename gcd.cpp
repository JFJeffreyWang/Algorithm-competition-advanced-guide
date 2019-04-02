#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

int main(){
    int a,b;
    while(cin>>a>>b && a){
        cout<<gcd(a,b)<<endl;
    }
}
