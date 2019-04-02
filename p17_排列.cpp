#include<iostream>


using namespace std;


void calc(int k){
    if (k == n + 1){
        for( int i = 1;i<=n;i+)
            printf("%d", order[i]);
        puts("");
        return;
    }
    for(int i = 1;i<=n;i++){
        if(chosen[i])continue;
        order[k] = i;
        chosen[i] = 1;
        calc(k + 1);
        chosen[i] = 0;
        order[k] = 0;
    }
}

int main(){
    cin >> n;
    calc(1);
}
