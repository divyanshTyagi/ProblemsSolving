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

int dp[18][262144];
int grid[18][18];
int n,m,k;
vi contribution;
void init(){
    for(int j =0 ; j < (1<<n)  ; j++){
        for(int i =0 ; i < n ; i++){
            if(((1<<i)&j) == 0) dp[i][j] = 0;
            else{
                dp[i][j] = contribution[i];
                int temp = j^(1<<i);
                for(int x =0 ; x < n ; x++){
                    if(temp&(1<<x)){
                        //cout << dp[x][temp] << " " << contribution[i] << " " << grid[x][i] << endl;
                        dp[i][j] = max(dp[x][temp] + contribution[i] + grid[x][i],dp[i][j]);
                    }
                }
            }
        }
    }
}


int32_t main(){

    memset(dp,0,sizeof(dp));
    memset(grid,0,sizeof(grid));
    cin >> n >> m >> k;
    rep(i,n){
        int x;
        cin >> x;
        contribution.pb(x);
    }
    rep(i,k) {
        int u,v,wt;
        cin >> u >> v >> wt;
        u--; v--;
        grid[u][v] = wt;
    }

    /*rep(i,n) cout << contribution[i] << " ";
    cout << endl;
    rep(i,18){
        rep(j,18) cout << grid[i][j] << " ";
        cout << endl;
    }*/

    init();
    int answer =INT_MIN ;
    for(int i = 0 ;i < (1<<n) ; i++){
       // rep(j,n) cout << j << " " << i << " " << dp[j][i] << endl;
        if(__builtin_popcountll(i) == m){
            for(int j =0 ; j < n ; j++) answer = max(answer,dp[j][i]);
        }
    }
    cout << answer << endl;
}

