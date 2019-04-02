#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int x){
    for(int i = 2; i <= sqrt(x); i ++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){
    int n = 0;
    for(int i = 100000;n<20; i++){
        if(isprime(i))cout<<i<<endl,n++;

    }

}
