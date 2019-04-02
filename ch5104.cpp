#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 18;

int a[N][N], f[N][N][N][2][2][N*N],n,m,K, v[N][N][N][2][2][N*N][6];



int main(){
    cin>>n>>m>>K;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++ ){
            cin>>a[i][j];
        }
    }
    int ans = 0, lu[6];

    for(int i = 0; i<=n-1; i++){
        for(int j = 0; j <= m; j++){
            for(int k = j; k <= m; k++){
                for(int l = 0; l <= 1; l++){
                    for(int ma = 0; ma <= 1; ma++){
                        for(int na = 0; na < K; na++ ){
                                for(int jj = 1; jj <= m; jj++ ){
                                    for(int kk = jj; kk <= m && (na+kk-jj+1)<=K; kk++){
                                        if(l==1 && jj<j || ma == 1 && kk >k )continue;
                                        int sum = 0;
                                        for(int iii = jj; iii<=kk; iii++){
                                            sum += a[i+1][iii];
                                        }
                                        f[i+1][jj][kk][ (jj>j)?1:l ][ (kk<k)?1:ma ][na+kk-jj+1] = f[i][j][k][l][ma][na] + sum ;
                                        int temp2[6] = {i,j,k,l,ma,ma};
                                        memcpy(v[i+1][jj][kk][ (jj>j)?1:l ][ (kk<k)?1:ma ][na+kk-jj+1],temp2,sizeof(temp2));

                                        if(na+kk-jj+1 == K){
                                            if(f[i][j][k][l][ma][na] + sum > ans){
                                                ans = f[i][j][k][l][ma][na] + sum ;
                                                int temp[6] = {i+1,jj,kk, (jj>j)?1:l , (kk<k)?1:ma ,na+kk-jj+1};
                                                memcpy(lu,temp,sizeof(lu));
                                            }
                                            continue;
                                        }

                                    }
                                }
                            }

                        }
                    }
                }
            }
        }

        cout<<ans<<endl;
        vector<pair<int,int> > anss;
        while(lu[0]!=0){
            for(int i = lu[1]; i<= lu[2];i++){
                anss.push_back(make_pair(lu[1], i));
            }
            memcpy(lu , v[lu[0]][ lu[1] ][ lu[2] ][ lu[3] ][ lu[4] ][ lu[5] ],sizeof(lu));
        }

        for(int i = 1; i <= anss.size(); i++){
            cout<<anss[i].first<<' '<<anss[i].second<<endl;
        }


    }




