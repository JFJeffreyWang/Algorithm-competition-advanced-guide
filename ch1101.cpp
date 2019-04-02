#include<iostream>
using namespace std;
int n;
#include<stack>
bool selected[23];
int odr[23],num = 0;
long long numans = 0;
stack<int> S;



void calc(int x){

    if(num == n ){
        numans++;
     //   for(int i = 1; i <= n; i++)cout<<odr[i];
       // cout<<endl;
        return;
    }
    if(S.size()){
        odr[++num] = S.top();
        S.pop();
        calc(x);
        num--;
        S.push(odr[num+1]);
    }

    if(x<=n){
        S.push(x);
        calc(x+1);
        S.pop();
    }



}

int main(){
    cin>>n;
    calc(1);
    cout<<numans;
}
