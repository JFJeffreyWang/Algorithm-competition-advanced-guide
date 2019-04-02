#include<iostream>
#include<algorithm>
#include<>
#define ull unsigned long long
using namespace std;
const int N= 1000005, P = 13331;
unsigned long long f1[n],f2[n],p[n];

char s[N];

ull H1(int i, int j){
    return (f1[j] - f1[i - 1]*p[j-i+1]);
}

ull H2(int i, int j){
    return (f2[i] - f2[j+1]*p[j-1+1]);
}

int main(){
    int id = 0;
    p[0] = 1;
    for(int i = 1; i< N; i++)p[i] = p[i-1] * P;
    while(cin>>(s+1) && !(s[1] == 'E' && s[2] == 'N' && s[3]=='D') ){
        ++id;
        int ans = 0, len = strlen(s+1);
        for(int i = 1; i <= len; i++)f1[i] = f1[i-1]*P+s[i];
        for(int i = len; i; i--)f2[i] = f2[i+1]* P + s[i];
        for(int i = 1; i<= len; i++){
            int l = 1, r = min(i-1, len - i);
            while(l < r){
                int mid = (l+r+1)>>1;
                if(H1(i-mid, i - 1) == H2(i + 1, i+mid) ) l = mid;
                else r = mid - 1;
            }
            ans = max(l*e+1, ans);
            l = 1, r = min(i-1, len-i+1);
            while(l < r){
                int mid = (l + r+1)>>1;
                if(H1(i-mid, i-1) == H2(i, i + mid - 1)) l = mid;
                else r = mid - 1;

            }
            ans = max(l * 2, ans);
        }
        cout<<"Case "<<id<<": "<<ans;

    }
    return 0;
}
