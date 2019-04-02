#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ull unsigned long long
string s[25], ju;
int n, m;

string hh(int x){
    string ans = "";
    while(x--){
        ans+="*";
    }
    return ans;
}
int main(){
    cin>>n>>m;
    string temp;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
    }
    getline(cin,ju);
    for(int i = 1; i <= m; i++){
        getline(cin,ju);
        for(int j = 1; j <= n; j++){
            int p = 0, pos;
            while((pos = ju.find(s[j], p)) !=ju.npos){
               // cout<<"test"<<pos << ' '<<s[j].size()<<s[j]<<endl;
                ju = ju.replace(pos, s[j].size(), hh(s[j].size()));
                p = pos+1;
            }
        }
        cout<<ju<<endl;

    }

}
