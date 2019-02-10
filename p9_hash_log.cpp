#include<iostream>
#include<bitset>
using namespace std;
long long lowbit(long long a){
    return a&(-a);
}
void numOne(long long a){
    int H[37];
    for (int i = 0; i< 36; i++)H[(1ll << i) % 37] = i;
    while(a > 0){
        cout << H[(a & -a) % 37]<<' ';
        a -= a & -a;
    }
    cout << endl;
}

int main(){
    long long a;
    cin >> a;
    cout << bitset<sizeof(a)*8>(a) << endl;
    numOne(a);
}
