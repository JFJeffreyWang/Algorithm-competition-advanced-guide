#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char s[1000005];
int m,la,lb,ra,rb;
unsigned int ha[1000005], p[1000005];

unsigned int kp(int a, int b){
    unsigned int ans = 1;
    unsigned int aa = a;
    while(b){
        if (b&1)ans = ans * aa;
        aa *= aa;
        b>>=1;
    }
    return ans;
}

int main(){
    scanf("%s",s+1);
    p[0] = 1;
    int strl = strlen(s+1);
    for(int i = 1; i<=strl; i++){
        ha[i] = ha[i-1]*31 +s[i]-'a'+1;
        p[i] = 31*p[i-1];
       // cout<<ha[i]<<' ';
      //  cout<<p[i]<<' ';

    }

    cin>>m;
    while(m--){
        cin>>la>>ra>>lb>>rb;
//        cout<<ha[ra]<<' '<<ha[la-1]<<' '<<p[ra-la+1]<<endl;
//        cout<<ha[rb]<<' '<<ha[lb-1]<<' '<<p[rb-lb+1]<<endl;
        if(ha[ra]-ha[la-1]*kp(31,ra-la+1) == ha[rb]-ha[lb-1]*kp(31,rb-lb+1) ) {
                cout<<"Yes"<<endl;
//                cout<<ha[ra-1]<<' '<<ha[la-1]<<' '<<p[ra-la+1]<<endl;
//                cout<<ha[rb+1]<<' '<<ha[lb-1]<<' '<<p[rb-lb+1]<<endl;
//                cout<<"test  "<<ha[ra]-ha[la-1]*p[ra-la+1]<<' '<<ha[rb]-ha[lb-1]*p[rb-lb+1]<<endl;}
        }
        else {cout<<"No"<<endl;
//        cout<<"test  "<<ha[ra]-ha[la-1]*p[ra-la+1]<<' '<<ha[rb]-ha[lb-1]*p[rb-lb+1]<<endl;

        }
        }
    }


