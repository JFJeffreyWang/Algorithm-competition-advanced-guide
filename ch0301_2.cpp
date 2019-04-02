#include<iostream>
using namespace std;
int c[20], n;

bool next(){
    int i = c[0];
    c[i+1] = n+1;
    while(i){
        if(c[i]<c[i+1] - 1){
                c[i]++;
                while(c[++i]!=n+1)
                    c[i] = 1+c[i-1];
                return 1;
        }
        i--;
    }
    if(c[0] == n) return false;
    c[0]++;
    for(int i = 1; i <= c[0]; i++)
        c[i] = i;
    return 1;

}

int main(){
    cin>>n;
    cout<<endl;
    while(next()){
        for(int i = 1; i <= c[0]; i++){
            cout<<c[i]<<' ';
        }
        cout<<endl;
    }
}
