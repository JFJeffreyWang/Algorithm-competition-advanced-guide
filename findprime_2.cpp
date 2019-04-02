#include<iostream>
#include<cmath>
using namespace std;
bool inprime(int x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i==0)return false;
    }
    return 1;
}
int main(){
    for(int i = 1000000;i <=1000050; i++){
        if(inprime(i))cout<<i<<endl;
    }
}
