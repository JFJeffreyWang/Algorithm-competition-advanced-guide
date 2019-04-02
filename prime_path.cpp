#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
bool v[10005];
bool vi[11][11][11][11];
int a[5], b[5], n;
int f[11][11][11][11];
int INF = 0x3f3f3f3f;
struct node{
    int s[5];
};
bool operator == (const node &a, const node & b){
    for(int i = 1; i <= 4; i++){
        if(a.s[i]!=b.s[i])return 0;
    }
    return 1;
}
queue<node > Q;

void print(node t){
    for(int i = 1; i <= 4; i++)cout<<t.s[i];

}

inline void biao(int x){
    int a, b, c, d;
    a = x%10;
    x/=10;
    b = x%10;
    x/=10;
    c = x%10;
    x/=10;
    d = x%10;
    vi[d][c][b][a] = 1;
   // cout<<vi[d][c][b][a]<< ' '<<d<< ' '<<c<< ' '<<b<< ' '<<a<<endl;
}
void prime(){
    for(int i = 2; i <= 9999; i++){
        if(v[i])continue;
        if(i>=1000)biao(i);
        for(int j = 2; j <= 10000/i; j++)v[j*i] = 1;
    }
}
inline  void setf(node no, int a){
    f[no.s[1] ][ no.s[2] ][no.s[3] ][no.s[4] ] = a;
}

inline int getf(node no){
    return f[no.s[1] ][ no.s[2] ][no.s[3] ][no.s[4] ];
}

inline bool getv(node no){
    return vi[no.s[1] ][ no.s[2] ][no.s[3] ][no.s[4] ];
}

int calc(){
    memset(f, 0x3f, sizeof(f));
    node temp = *(new node());
    memcpy(temp.s, a, sizeof(a));
    node zd = *(new node());
    memcpy(zd.s, b, sizeof(b));
    queue<node > eQ;
    swap(eQ,Q);

    setf(temp,0);
    Q.push(temp);

    while(Q.size()){
        node t = Q.front();
        Q.pop();
        if(t==zd) return getf(t);
        int now  = getf(t);
        for(int j = 1; j <=4;j++ ){
            node temp = t;
            for(int i = 0; i<=9 ; i++){
                temp.s[j] = i;
                if(getv(temp) && getf(temp) == INF){
                    Q.push(temp);
//                    cout<<"Q push ";
//                    print(temp);
//                    cout<< ' '<<now + 1<<endl;
                    setf(temp, now+1) ;
                }
            }

        }

    }

}
int main(){
    prime();
  //  cout<<vi[1][0][3][4]<<' '<<v[1034];
    cin>>n;
    int aa, bb;
    while(n--){
        cin>>aa>>bb;
        for(int i = 4; i >=1 ; i--){
            a[i] = aa%10;
            b[i] = bb%10;
            aa/=10;
            bb/=10;
        }
        cout<<calc()<<endl;
    }
}
