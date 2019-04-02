#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

stack<pair<int,int> > S;
priority_queue<pair<int,int> > Q, C;
int n, m;

bool pick(int l, int r){
    while(S.size() && S.top().first <= r){
        Q.push(S.top());
        S.pop();
    }
    while(Q.size() && Q.top().first > r){
        S.push(Q.top());
        Q.pop();
    }
    int a,b;
    if(Q.size() && Q.top().first >= l){
        a = Q.top().first;
        b = Q.top().second;
        Q.pop();
        if(b>1)Q.push(make_pair(a,b-1));
        //cout << l << r << a <<endl;
        return 1;
    }
    return 0;

}

int main(){

    cin >> n >> m;
    int a,b,ans = 0;
    while(n--){
        cin>>a >> b;
        C.push(make_pair(a,b));
    }
    while(m--){
        cin >> a >> b;
        Q.push(make_pair(a,b));
    }
    while(C.size()){
        if(pick(C.top().first, C.top().second)){
            ans++;
        }
        C.pop();
    }
    cout<< ans;


}
