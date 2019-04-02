#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;



void out(int n, int r, bool b ){
    if(n==1){
        if(b)cout<<'X';
        else cout<<' ';
        return;
    }
    int temp  = pow(3,n-2);
    if(!b){for(int i = 1; i <= 3*temp; i++)cout<<' ';return;}
    if(r>=1 &&r <= temp){
        out(n-1, r,1);
        out(n-1, r,0);
        out(n-1, r,1);
    }
    else if(r <=2*temp){
        out(n-1, r-temp,0);
        out(n-1, r-temp,1);
        out(n-1, r-temp,0);
    }
    else if(r <= 3*temp){
        out(n-1, r-2*temp,1);
        out(n-1, r-2*temp,0);
        out(n-1, r-2*temp,1);
    }


}

void rout(int x){
    int temp = pow(3,x-1);
    for(int i = 1; i <= temp; i++){
        out(x, i, 1);
        cout<<endl;
    }
    cout<<"-"<<endl;

}

int main(){
    int n;
    while(cin>>n && n !=-1){
        rout(n);
    }


}
