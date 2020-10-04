#SOLVED
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

int dp[13][99];


void init(){
    dp[1][0] = 1;
    for(int i = 2 ; i <= 12 ; i++){
        for(int j = 0 ; j < 99 ; j++){
            if(j == 0) {
                dp[i][j] = 1 ;
            }
            else{
                for(int p = 0 ; p<=(i-1) ; p+=1){
                    if((j-p)>=0) dp[i][j] += dp[i-1][j-p];
                }
            }
        }
    }
}


int32_t main(){
    memset(dp,0,sizeof(dp));
    init();
    int d;
    cin >> d;
    while(d--){
        int n,k;
        cin >> n >> k;
        cout << dp[n][k] << endl;


    }

}
