#include<iostream>
using namespace std;
const int N = 26;
int n, num = 0, st[N], top = 0, ans[N], t = 0;

void z(int x){
    if( x == n + 1){
        if( ++ num > 20) exit(0);
        for(int i = 1; i <= t; i++) cout<<ans[i];
        for(int i = top; i; i--) cout<<st[i];
        cout << endl;
        return;
    }
    if(top){
        ans[++t] = s[top--];
        z(x);
        st[++t] = ans[t--];
    }

    st[++top] = x;
    z(x + 1);
    --top;
}

int main(){
    cin >> n;
    z(1);
    return 0;
}
