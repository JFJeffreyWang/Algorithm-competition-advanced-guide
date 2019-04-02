#include<iostream>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;

int n, m, a;
set<pair<int, int> > s;

int main(){
    cin>>n;
    cin>>a;
    s.insert(make_pair(a,1));
    for(int i = 2; i <=n; i++){
        cin>>a;
        int ans = 0x3f3f3f3f, ansi;
        set<pair<int,int> > :: iterator ite1 = s.lower_bound(make_pair(a,i));

        if(ite1 != s.begin() ){
            ite1--;
            ans = a - (*ite1).first;
            ansi = (*ite1).second;
            ite1++;
        }
        if(ite1!=s.end() && (*ite1).first-a<ans){
            ans = (*ite1).first-a;
            ansi = (*ite1).second;
        }
        s.insert(make_pair(a,i));
        cout<<ans << ' ' << ansi << endl;



    }


}
