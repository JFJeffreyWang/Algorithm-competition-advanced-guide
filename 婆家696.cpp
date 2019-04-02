#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
ll l,len,p;


int main(){
    int num = 0;
    while(cin>>l && l){
    num++;
    len = 1;
    p = 8;
    while(p%l!=0 && len <18){
        p=10*p+8;
        len++;
    }
    len = (len==18)?0:len;
    cout<<"Case "<<num<<": "<<len<<endl;

    }
}
