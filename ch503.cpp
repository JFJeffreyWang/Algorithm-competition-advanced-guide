#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 250009;
int n, x[N];

bool calc(){

    bool ans = 0;
    bool flag = 0;
    for(int i = 1; i<= n*n; i++){
        cin>>x[i];

    }
    for(int i  = 1; i<= n*n-1; i++){
        for(int j = i+1; j<=n*n ; j++){
            if(x[i]&&x[j] &&x[i]>x[j]) ans = !ans;
        }
    }
    return ans;
}

int main(){
    while((cin>>n) && n){
        if(!(calc()^calc()))cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }

}
