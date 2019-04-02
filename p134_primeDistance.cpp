#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> prime;
int n,m,pn=2,pm=2;
bool isp[1000008];
bool s[70000];


void Sprime(){
    if (pn == pm)return;

    for(int i=pn;i<=pm;i++){
        if(s[i])continue;
        prime.push_back(i);
        for(int j=i;j<=m/i;j++){
            s[i*j]=1;
        }
    }
    pn=(pm=pm+1);


}

int main(){
    memset(s,0,sizeof(s));
    while(cin>>n>>m){
        pm=m;
        Sprime();
        int sizeP = prime.size();
        memset(isp,0,sizeof(isp));
        for(int i=0;i<sizeP;i++){
            for(int j=(n-1)/prime[i] + 1;j<m/prime[i];j++){
                isp[j*prime[i]-n]=1;
            }
        }


//        memset(prime,0,sizeof(prime));
        for(int i=n;i<=m;i++){
            if(isp[i-n])continue;
            prime.push_back(i);
        }
        int num = prime.size(),M=m,m=0;
        if (num<2)cout<<"There are no adjacent primes."<<endl;
        for(int i=1;i<num;i++){
            if()

        }

    }
}
