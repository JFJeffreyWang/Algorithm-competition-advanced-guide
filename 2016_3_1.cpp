#include<iostream>
using namespace std;
const double eps = 1e-5;

int Bike(double x){
    return 50+x/3.0;
}
int zl(double x){
    return x/1.2;
}

int main(){
    int x;
    int n;
    cin>>n;
    while(n--){
        cin>>x;
       if(x > 100)cout<<"Bike";
       else if(x<100)cout<<"Walk";
       else cout<<"All";
       cout<<endl;
    }

}
