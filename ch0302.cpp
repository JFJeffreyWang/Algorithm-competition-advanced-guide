#include<iostream>
using namespace std;
int n,m;

bool eq(int x, int n){
    int num = 0;
    while(x){
        if(x&1){
            num++;
            if(num>n){
                return 0;
            }
        }
        x>>=1;
    }
    if(num == n)return 1;
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i = ((1<<n)-1);i>=0;i--){
        if(eq(i,m)){
            for(int j = 1;j<=n;j++){
                if((i)&(1<<(n-j)))cout<<j<<' ';
            }
            cout<<endl;
        }

    }
}
