#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
priority_queue<int> lQ;
priority_queue<int, vector<int>, greater<int> > rQ;
int t, n ,m, INF = 0x3f3f3f;

void in(int x){
    if(x<=lQ.top())lQ.push(x);
    else(rQ.push(x));
}

int out(){
    int ans;
    while(lQ.size()>rQ.size()+1){rQ.push(lQ.top());lQ.pop();}
    while(rQ.size()>lQ.size()+1){lQ.push(rQ.top()); rQ.pop();}
    // cout<<endl<<"lQ "<<lQ.size()-1<<"  rQ "<<rQ.size()-1<<endl;
    if(lQ.size() == rQ.size() ){
        return(lQ.top()+rQ.top())/2;
    }
    if(lQ.size()>rQ.size()) return lQ.top();
    return rQ.top();
}


void calc(){
    int temp;
    priority_queue<int> elQ;
    priority_queue<int, vector<int>, greater<int> > erQ;
    swap(elQ,lQ);
    swap(erQ,rQ);
    lQ.push(-INF);
    rQ.push(INF);
    cin>>m>>n;
    cout<<m <<' '<< (n+1)/2<<endl;
    cin>>temp;
    in(temp);
    cout<<temp<<' ';
    n = ((n+1)/2)-1;
    int num = 1;
    while(n--){
        cin>>temp;
        in(temp);
        cin>>temp;
        in(temp);
        temp = out();

        if(num==10){
            cout<<endl;
            num = 0;
        }
        cout<<temp<<' ';
        num++;
    }
    cout<<endl;

}

int main(){
    cin >> t;
    while(t--)calc();
}
