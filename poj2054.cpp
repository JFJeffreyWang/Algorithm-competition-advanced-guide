#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1006;
int selected[N], father[N], val[N];

struct node{
    double val;
    int num;
    node* nxt = NULL;
    bool operator < (const node s) const{
        return val < s.val;
    }
}Node[N];

priority_queue<node> Q;
int n, r;

void calc(){
    int ans = 0;
    int num = 1;
    int a, b;
    memset(selected,0,sizeof(selected));
    selected[r] = 1;
    ans += val[r]*(num++);

    for(int i = 1; i<=n; i++){
        cin>>val[i];
        Node[i].val = val[i];
        Node[i].num = i;
        if(i!=r)Q.push(Node[i]);
    }
    for(int i = 1; i < n; i++){
        cin>>a>>b;
        father[b] = a;
    }

    while(Q.size()){
        if(!selected[father[Q.top().num] ] ){
            node top = Q.top();
            node temp = *(new node());
            temp.val = (top.val + val[father[top.num]])/2.0;
           // cout<<"test "<<temp.val<<endl;
            temp.num = father[top.num];
            temp.nxt = &top;
            //cout<<"pop "<<Q.top().num <<endl;
            Q.pop();
            Q.push(temp);
        }
        else if(selected[Q.top().num]){
            node top = Q.top();
            Q.pop();
            if(top.nxt)Q.push(*(top.nxt));
        }
        else {
            ans += (num++)*val[Q.top().num];
            selected[Q.top().num] = 1;
            node top = Q.top();
            //cout<<top.num << ' ' << ans<< endl;
            Q.pop();
            if(top.nxt)Q.push(*top.nxt);

        }
    }
    cout<<ans<<endl;


}


int main(){
    while(cin>>n>>r && n && r){
        calc();
    }

}
