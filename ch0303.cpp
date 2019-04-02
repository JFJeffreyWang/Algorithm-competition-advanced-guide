#include<iostream>
#include<algorithm>
using namespace std;
int c[15], n;

inline void print(){
    for(int i = 1; i <= n; i++)cout<<c[i]<<' ';
    cout<<endl;
}
int main(){
    cin>> n ;
    for(int i = 1; i <= n; i++)c[i] = i;
    print();
    while(next_permutation(c+1, c+n+1)){
        print();
    }
}
