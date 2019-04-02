#include<iostream>
using namespace std;
int c[30], n;

void calc(int x){
    if(x == n+1){
        for(int i = 1; i <= c[0]; i++){
            cout<<c[i]<<' ';
        }
        cout<<endl;
        return ;
    }
    calc(x+1);
    c[++c[0]] = x;
    calc(x+1);
    c[0]--;
}

int main(){
    cin>>n;
    calc(1);
}
