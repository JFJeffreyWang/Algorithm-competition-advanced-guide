#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int sum, a[70],v[70],n,  cnt, top;

bool dfs(int stick, int cab, int last){
    if(stick >=cnt)return 1;
    if(cab == top){
        return dfs(stick+1, 0, 1);
    }
    int fail = 0;
    for(int i =last; i<=n; i++){
        if(!v[i]  && cab + a[i] <= top && a[i]!=fail){
            bool flag = 0;
            v[i] = 1;
            if(dfs(stick, cab+a[i], i+1))flag = 1;
            v[i] = 0;
            if(flag) return 1;
            fail = a[i];
            if(cab == 0 || cab + a[i]==top) return 0;
        }


    }
    return 0;

}


int main(){
    while(cin>>n && n){
        memset(v,0,sizeof(a));
        sum = 0;
        int maxa = 0;
        for(int i = 1; i<= n; i++){
            cin >> a[i];
            sum += a[i];
            maxa = max(maxa, a[i]);
        }
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        int len = 0;
        for(int i = maxa; i<=sum/2; i++){
            if(sum%i != 0)continue;
            cnt = sum/i;
            top = i;
            if(dfs(1, 0, 1)){
                len = i;
                break;
            }
        }
        cout <<((len == 0)?sum:len)<<endl;
    }
}
