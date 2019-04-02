#include<iostream>
#include<cstring>
using namespace std;
string s;
int main(){

    getline(cin,s);
    while(s!="ENDOFINPUT" ){

        getline(cin, s);
        //cout<<s<<endl;
        int len = s.size();
        for(int i = 0; i<len; i++){
            char t = s[i];
            if(t>='A' && t <= 'Z') cout<< (char)('A'+(t-'A'-5+26)%26);
            else cout<<t;
        }
        cout<<endl;
        getline(cin,s);
        getline(cin,s);
    }

}
