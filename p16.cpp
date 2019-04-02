#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<=(1<<n)-1;i++){
        for(int j=1;j<=n-1;j++){
            if((i>>(j-1))&1) cout<<j<<' ';
        }
        if((i>>(n-1))&1) cout<<n;
        cout<<endl;

    }
}
