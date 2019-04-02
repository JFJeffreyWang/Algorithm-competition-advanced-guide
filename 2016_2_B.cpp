#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


string in(){
    string s,ans = "";
    getline(cin, s);

    for(int i = 0; i < s.size(); i++){
        if(s[i]>='a' && s[i] <= 'z')ans = ans + s[i];
        else if(s[i]>='A' && s[i] <= 'Z') ans = ans + (char)(s[i] + 32);
    }
    return ans;

}
int main(){
    string a = in();
    string b = in();
    if(a == b)cout<<"YES";
    else cout<<"NO";
}
