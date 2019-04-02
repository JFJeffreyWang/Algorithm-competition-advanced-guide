
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 10000;
int n,m,sp[N],spz[N],num,v[N+5],zs[N], sum = 0;

void zs(){
    int numb = 0;
    memset(v,0,sizeof(v));
    for(int i = 2; i<= sqrt(N);i++){
            if(v[i])continue;
        zs[++numb] = i;
        for(int j = i; j<=N/i; j++){
            v[i*j] = 1;
        }
    }
}

int solve(){
    int numb = 1;
    while(zs[numb]){
        if(!(n%zs[numb]){
           sp[++num] = zs[numb];
            while(!(n%zs[numb])){
                n = n/zs[numb];
                spz[zs[numb]]++;
           }

        }
        numb++;
    }

}

void suma(){

}
void solve2(){
    int num = 1;
    while(sp[num]){
        if(spz[sp[num]]){
            spz[sp[num]--;
            suma();
            solve2();
            spz[sp[num]]++;
        }
    }

}


int main(){
    cin>>n,m;
    zs();
    solve();
    int num = 1;
    while(sp[num]){
        spz[sp[num]] *= m;
        num++;
    }
    solve2();
}
