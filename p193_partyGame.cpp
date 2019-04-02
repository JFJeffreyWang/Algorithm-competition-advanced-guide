#include<instream>
#include<map>;
#include<cstring>;
int ques[5005][3],t,h[10006];
string str;
map<int,int> M;
vector<pair<int,int> > V;


void read_discrete(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin>>ques[i][0]>>ques[i][1];
        ques[i][0]--;
        cin>>str;
        if(str[0] == 'e'){
            ques[i][2] = 0;
        }else{
            ques[i][2] = 1;
        }
        if(!M[ques[i][0]])M[ques[i][0]]=++t;
        if(!)M[ques[i][1]])M[ques[i][1]]=++t;

    }

}

int main(){

    for(int i=1;i<10004;i++){
        h[i]=i;
    }
    read_discrete();


}
