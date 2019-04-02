#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int tri[15], qua[15];




int main(){
for(int i = 0; i <= 12; i++)
    tri[i+1] = 2*tri[i] + 1;

memset(qua, 0x3f, sizeof(qua));
qua[0] = 0;
for(int i = 1; i <= 12; i++){
for(int j = 0; j <= i-1; j++){
    qua[i] = min(qua[i], 2*qua[j] + 2 * tri[i-j-1] + 1);
}

cout<<qua[i]<<endl;
}


}

