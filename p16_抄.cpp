#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int> chosen;

void calc(int x){
    if(x == n + 1 && chosen.size()==m){
        for(int i = 0; i < chosen.size(); i++)
            printf("%d ",chosen[i]);
        puts("");
        return;
    }
    if(chosen.size()>m || chosen.size()+ 1 +(n-x)<m )return;
    calc(x+1);
    chosen.push_back(x);
    calc(x+1);
    chosen.pop_back();
}

int main(){
    cin >> n >> m;;
    calc(1);
}
