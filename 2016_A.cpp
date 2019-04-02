#include<iostream>
using namespace std;

int main(){
    int n;
    int a[1005],total = 0, b[1005];
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    for(int i =1 ; i <= n; i++){
            cin>>b[i];
        total += a[i] * b[i];
    }
    cout<<total;
}
