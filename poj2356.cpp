#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N = 10005;
int n, a[N], J[N][N], ansi = 0;
bool  v[N];
vector<int>ans,OK;



int main(){

    cin>>n;
    int BIGNUM = n*(1000000/n);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    v[a[1] % n] = 1;
    OK.push_back(a[1] % n);
    J[1][a[1] % n] = 1;

    for(int i = 2; i <= n; i++ ){
        if(v[0] == 1) {
            ansi =i-1;
            break;
        }
        for(int j = OK.size()-1; j>=0  ; j--){
            int temp =(OK[j] + a[i])%n;
            if(!v[temp]){
                v[temp] = 1;
                OK.push_back(temp);
                J[i][temp] = 1;
            }
        }
    }
    if(v[0] == 1)ansi = n;

    if(ansi){
        int ansj = 0;
        while(ansi){
            if(J[ansi][ansj]){
                ans.push_back(a[ansi]);
                ansj = (ansj-a[ansi]+BIGNUM)%n;
            }
            ansi--;
        }
        cout<<ans.size()<<endl;
        for(int i = ans.size()-1; i>=0; i--){
            cout<<ans[i]<<endl;
        }


    }
    else{
        cout<<'0'<<endl;
    }



}
