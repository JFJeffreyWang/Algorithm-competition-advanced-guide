#include<iostream>
#include<cstring>
using namespace std;
char s[205], ans[205];

int main(){
    while(cin>>s+1){
        int len = strlen(s+1);
        for(int i = 1 ; i<=len; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ans[i] =  'A'+(int)(s[i]-'A'-5+26)%26;
            }
            else{
                ans[i] = s[i];
            }
        }
        for(int i = 1 ; i<=len; i++){
            cout<<ans[i];
        }
        cout<<' ';
    }
}
