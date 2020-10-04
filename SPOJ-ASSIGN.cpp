#SOLVED
#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 100005
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int> >
#define debug cout <<  "here" << endl;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
using namespace std;
int n;
int solve(vvi &grid,vi &dp){
    for(int i = 0 ;i < (1<<n) ; i++){
        int curr_idx = __builtin_popcountll(i);
        if(curr_idx == 0){
            dp[0] = 1;
            continue;
        }
        curr_idx--;
        // so we are not at the ith index , we can choose to remove anyone set bit
        for(int j = 0 ; j < n ; j++){
            int curr_mask = (1<<j);
            if((curr_mask&i) == 0 ) continue;
            if(grid[curr_idx][j] == 0) continue;
            dp[i]+=dp[(i^curr_mask)];
        }
    }
    return dp[(1<<n)-1];
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n ;
        vvi grid(n,vi(n,0));
        rep(i,n) rep(j,n) cin >> grid[i][j];
        vi dp((1<<n),0);
        cout << solve(grid,dp) << endl;
    }
}
