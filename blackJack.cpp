#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 13, INF = 0x3f3f3f3f;
int n, m, a[N];

int calc(){
    cin>>n;
    string temp;
    int cnt = 0, total = 0;
    for(int i = 1; i <= n; i++){
        cin>>temp;
        if(temp=="A"){a[i] = 11;cnt++;}
        else if(temp=="10" || temp == "J" || temp=="Q" || temp=="K") a[i] = 10;
        else a[i] = temp[0]-'0';
        total += a[i];
    }
    if (n==2 && cnt==1){
        if(a[1]==10 || a[2]==10)return INF;
    }
    while(total>21 && cnt>0){
        total -= 10;
        cnt--;
    }
    return total;
}

int main(){

    int numA = calc();
    int numb = calc();
    if(numb>21 && numb !=INF){cout<<"win";return 0;}
    if(numA>21 && numA != INF){cout<<"lose";return 0;}
    if(numA == numb){cout<<"draw"; return 0;}
    if(numA>numb){cout<<"win";return 0;}
    cout<<"lose";return 0;


}
