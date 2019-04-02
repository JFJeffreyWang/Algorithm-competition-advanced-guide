#include<iostream>
#include<map>
using namespace std;
map<pair<int,int>,pair<int,int> > M;

string trans(string str){
    string str1;
    int i = -1;
    int n = 0;
    while(str[++i]){
        if(str[i] == '-')continue;
        if(str[i] == '0'){
                str1=str1+'0';
        }
        else{
            int ch=(str[i]-'A')/3;
            char ch1='2'+ch;
            str1=str1+ch1;
        }

        n++;
        if(n==3){
            str1 = str1+'-';
        }
    }
    return str1;
}

int main(){
    cout << (16>>4 &1);

}
