#include<iostream>
#include<algorithm>
#include<cstring>
int ans , n, a[100007];

using namespace std;
int main(){
    cin>>n;
    for(int i =0; i<n; i++){
        cin>>a[i+1];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n /2 ; i++){
        ans += a[n-i+1] - a[i];
    }
    cout<< ans;

}
