#include<iostream>
using namespace std;
int c[30], n, m;

void calc(int x){
    if(c[0] > m || c[0] + n-x+1 < m) return;
    if(x == n+1){

        for(int i = 1; i <= c[0]; i++){
            cout<<c[i]<<' ';
        }
        cout<<endl;
        return ;
    }
    c[++c[0]] = x;
    calc(x+1);
    c[0]--;
    calc(x+1);

}

int main(){
    cin>>n >> m;
    calc(1);
}
