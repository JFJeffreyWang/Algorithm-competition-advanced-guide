#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int cnt[15];
stack<int> S[15];
char temp;
int main(){
    for(int i = 1; i <= 13; i++){
        for(int j = 1; j <= 4; j++){
            cin>>temp;
            if(temp>='1' && temp <='9')S[i].push(temp-'0');
            else if(temp == '0')S[i].push(10);
            else if(temp == 'J')S[i].push(11);
            else if(temp == 'Q')S[i].push(12);
            else if(temp == 'K')S[i].push(13);
            else if(temp == 'A')S[i].push(1);

        }
    }
    while(S[13].size()){
        S[14].push(S[13].top());
        S[13].pop();
    }
    swap(S[13],S[14]);

    int n = S[13].top();
    S[13].pop();
    while(1){
        cnt[n]++;
        if(!S[n].size())break;
        int t = n;
        n = S[t].top();
        S[t].pop();
    }
    int ans = 0;
    for(int i = 1; i <= 12; i++){
        if (cnt[i]==4)ans++;
    }
    cout<<ans;

}
