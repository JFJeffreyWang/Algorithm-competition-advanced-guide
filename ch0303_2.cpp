#include<iostream>
using namespace std;
bool chosen[15];
int ans[15], n;
void calc(int x){
    if(x == n+1){
        for(int i =1; i <= n; i++)cout<<ans[i]<<' ';
        cout<<endl;
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(chosen[i]) continue;
        chosen[i] = 1;
        ans[x] = i;
        calc(x+1);
        chosen[i] = 0;
    }


}

int main(){
    cin >> n;
    calc(1);
}
