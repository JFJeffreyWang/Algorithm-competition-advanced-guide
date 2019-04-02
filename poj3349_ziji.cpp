#include<iostream>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;

const int N = 100006, P = 100003;
int n, a[6], b[6];
struct S{
    int s[6];
};
vector<S> snow[N];

int H(){
    int s= 0, k = 1;
    for(int i = 0; i < 6; i++){
        s = (s+a[i])%P;
        k = ((ll)k*a[i])%P;
    }
    return(s+k)%P;
}
bool pd(){
    cout<<"test"<<endl;
    for(int i = 0; i < 6; i++){
            bool flag = 1;
        for(int j = 0; j<6; j++){
            if(a[(i+j)%6] != b[j]){
                flag = 0;
                break;
            }

        }
        if(flag)return 1;
        flag = 1;
        for(int j = 0 ;j < 6; j++){
            if(a[(i+j)%6] != b[(6-j)%6]){
                flag = 0;
                break;
            }
        }
        if(flag) return 1;
    }
    return 0;
}

int insert(){
    cout<<"ti"<<endl;
    int h = H();
    for(unsigned int i = 0; i< snow[h].size(); i++){
        memcpy(b,snow[h][i].s,sizeof(b) );
        if(pd() ) return 1;
    }
    S s;
    memcpy(s.s, a, sizeof(s.s));
    snow[h].push_back(s);
    return 0;
}


int main(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j < 6; j++) cin>>a[j];
        if(insert()){
            cout <<"Twin snowflakes found." <<endl;
            return 0;
        }
    }
    cout<< "No two snowflakes are alike."<<endl;
    return 0;

}
