#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool r[105], c[105];
int main(){
    int temp;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>temp;
            if(temp==1){
                r[i] = !r[i];
                c[j] = !c[j];
            }
        }
    }
    int a= 0, b = 0, e, d;
    for(int i = 1; i <= n; i++){
        if(r[i]){
            a++;
            e = i;
        }
        if(c[i]){
            b++;
            d = i;
        }
    }
    if(a == 0 && b == 0){
        cout<<"OK";
    }
    else if(a == 1 && b == 1){
        cout<<e << ' ' << d;
    }
    else cout << "Corrupt";


}

