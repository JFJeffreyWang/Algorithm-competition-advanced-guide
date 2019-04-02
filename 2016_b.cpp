#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
string s[10006],mail, a,b,c;

string rev(string x){
    for(int i = 0; i < x.size(); i++){
        if(x[i]>='a' && x[i] <= 'z'){
            x[i] = x[i]-32;
        }
        else if(x[i] >= 'A' && x[i] <= 'Z'){
            x[i] = x[i] + 32;
        }
    }
    return x;
}

int main(){
    cout<<'A'-'a';
    cin>>mail>>n;
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        cin>>a>>b>>c;
        if(mail==c){cout<<a<<' '<<rev(b)<<endl;flag = 0;}
    }
    if(flag)cout<<"empty"<<endl;
}
