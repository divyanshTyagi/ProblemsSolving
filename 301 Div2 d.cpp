#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 100005
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define debug cout <<  "here" << endl;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
using namespace std;

float r[101][101][101];
float p[101][101][101];
float s[101][101][101];



float compute(float arr[101][101][101],int rock,int paper,int sciss){

    rep(p,101){
        rep(s,101){
            arr[0][p][s] = 0;
        }
    }

    rep(r,101){

        if(r==0) continue;

        rep(p,101){

            rep(s,101){
                int total = r+p+s;
                float rr,pp,ss;

                if(total == 1){
                    arr[r][p][s] = 1.0;
                    continue;
                }

                rr = (r*(r-1))/((1.0*(total)*(total-1)));
                pp = (p*(p-1))/((1.0*(total)*(total-1)));
                ss = (s*(s-1))/((1.0*(total)*(total-1)));

                if(p==0 && s==0) arr[r][p][s] = 1.0;

                if(s!=0){
                    arr[r][p][s] += ((1.0*r*s*2)/(1.0*(total)*(total-1)))*arr[r][p][s-1]*(1.0/(1-rr-pp-ss));
                }
                if(p!=0){
                    arr[r][p][s] += ((1.0*r*p*2)/(1.0*(total)*(total-1)))*arr[r-1][p][s]*(1.0/(1-rr-pp-ss));
                }
                if(p!=0 && s!=0) arr[r][p][s] += ((1.0*s*p*2)/(1.0*(total)*(total-1)))*arr[r][p-1][s]*(1.0/(1-rr-pp-ss));
            }
        }
    }
    rep(i,3){
        rep(j,3){
            rep(k,3){
            //cout << i << " " << j << " " << k << " -- " << arr[i][j][k] << endl;

            }
        }
    }

    return arr[rock][paper][sciss];

}



int32_t main(){

    memset(r,0,sizeof(r));
    memset(p,0,sizeof(p));
    memset(s,0,sizeof(s));


    int rocks,paper,sciss;
    cin >> rocks >> sciss >> paper;
    cout << fixed << setprecision(10);
    cout << compute(r,rocks,paper,sciss) << " ";

    cout << compute(s,sciss,rocks,paper) << " ";
    cout << compute(p,paper,sciss,rocks);

}
