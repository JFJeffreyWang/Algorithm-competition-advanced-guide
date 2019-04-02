#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, na,nb,a[105], b[105] ;

int play(int x, int b){
    int c = x-b;
    if(c == 5 || c == -2 || c == -3)return 1;
    if(c==0)return 0;
    return -1;

}


int main(){
    cin>>n>>na>>nb;
    int ans = 0;
    for(int i = 0; i < na; i++){
        cin>>a[i];
    }
    for(int i =0; i < nb; i++)cin>>b[i];

    int i = 1, j = 1;
    for(int k = 1; k <= n;k++ ){
        ans+=play(a[(i++)%na], b[(j++)%nb] );
    }
    if(ans>0)cout<<"A";
    else if(ans == 0)cout<<"draw";
    else cout<<"B";

}
