#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s[1000005], num;

void calc_next(){
    next[1] = 0;
    for(int i = 2, j = 0; i <= n; i++){
        while(j > 0 && a[i] != a[j+1]) j = next[j];
        if(a[i] == a[j+1])j++;
        next[i] = j;
    }
}

int main(){
    while(cin>>n && n){
        cin>>s+1;
        cslc_next();
        cout<<"est case #"<<++num<<endl;
        for(int i = 2; i <= n; i++){
            if(i % (i-next[i]) == 0 && i / (i - next[i]) > 1)
                cout<<i << ' ' << i / (i - next[i]);
        }
        cout<<endl;
    }
}
