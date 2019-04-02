#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int f,n;

int main(){
    cin>>n;
    for(int i = 0; i <= (1<<n)-1; i++){
        for(int j = 0; j <= n-1; j++){
            if(i>>j & 1) cout<<j+1<<' ';
        }
        cout<<endl;
    }
}


