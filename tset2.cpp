#include<set>
#include<iostream>
using namespace std;
set<int> S;
int main(){
    S.insert(3);
    S.insert(4);
    S.insert(6);
    S.insert(7);
    cout<< *S.lower_bound(5) << endl << *S.upper_bound(5);
}
