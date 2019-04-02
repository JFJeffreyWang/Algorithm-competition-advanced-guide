#include<iostream>
using namespace std;
int main(){
    int n = 15, k = 2;
    cout<<((n >> k) & 1) << endl << (n & ((1<<k)-1)) << endl;
    cout<< (n ^ (1<<k)) << endl;
    cout<< (n | (1 << k)) <<endl;
    cout<< (n & (~( 1 << k)) ) <<endl;
}
