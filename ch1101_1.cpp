#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
int cnt ,s[25], ans[25],sT= 0,aT = 0, n;

void calc(int x){
    if(cnt>=20 )return;
    if(x == n+1){
        for(int i = 1; i <= aT; i++){
            cout<<ans[i];
        }
        for(int i = sT; i  >= 1; i--){
            cout<<s[i];
        }
        cout<<endl;
        cnt++;
        return;
    }

    if(sT){
    ans[++aT] = s[sT--];
    calc(x);
    s[++sT] = ans[aT--];
    }

    s[++sT] = x;
    calc(x+1);
    sT--;


}

int main(){
    cin>>n;
    calc(1);

}
