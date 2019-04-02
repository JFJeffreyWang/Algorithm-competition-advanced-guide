#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int a[10]={1,2,3,4,5};
    for(int i = 0;i<=9;i++)a[i] = i+10;
    cout<<*max(a+1,a+4)<<' '<<*min(a+1,a+4);
}
