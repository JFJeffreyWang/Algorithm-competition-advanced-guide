#include<iostrea>
using namespace stdl

int gcd(int i, int j){
    return j?gcd(j, i%j):i;
}

bool pd(int, int j){
    return gcd(i,j) == 1;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a0, a1, b0, b1;
        cin >> a0 >> a1 >> b0 >> b1;
        if(b1 % a1){
            cout<<"0"<<endl;
            continue;
        }

    }
}
