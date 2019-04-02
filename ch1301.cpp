#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > rQ;
priority_queue< pair<int,int> > lQ;
int n;

pair<int,int> out(int x){
    while(lQ.top().first>x){
        rQ.push(lQ.top());
        lQ.pop();
    }
    while(rQ.top().first < x){
        lQ.push(rQ.top());
        rQ.pop();
    }
    if(x-lQ.top().first > rQ.top().first - x){
        return rQ.top();
    }
    return lQ.top();

}
int main(){
    cin >> n;
    lQ.push(make_pair(-0x7fffff,0));
    rQ.push(make_pair(0x7fffff,0));
    int temp;
    pair<int, int> tempP;
    cin>>temp;
    lQ.push(make_pair(temp,1));
    for(int i = 2; i<=n; i++){
        cin>>temp;
        tempP = out(temp);
        cout<<abs(temp- tempP.first)<< ' ' << tempP.second<<endl;
        lQ.push(make_pair(temp, i));
    }
}
