// SOLVED
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


int dp[300005];
int dpV[300005];
vector<pi> edge(300005);
vector<int> edgeWt(300005);

void solve(int ind,int wt){
    int u = edge[ind].ff;
    int v = edge[ind].ss;


    if(dpV[v]!=-1){
        dp[ind] = 1 + dpV[v];
    }
    else dp[ind] = 1;
    /*dp[ind] = 1;
    for(auto node : adj[v]){
        int newIndex = node.ff;
        if(edgeWt[newIndex]>wt){
            dp[ind] = max(dp[ind],1+dp[newIndex]);
        }
    }
    return dp[ind];*/
}





int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int u,v,wt;
        cin >> u >> v >> wt;
        edge[i] = {u,v};
        edgeWt[i] = wt;
    }

    memset(dp,-1,sizeof(dp));
    memset(dpV,-1,sizeof(dpV));
    vector<pi> indexWt;
    for(int i =0 ; i < m ; i++){
        indexWt.pb({edgeWt[i],i});
    }
    sort(indexWt.begin(),indexWt.end());
    reverse(indexWt.begin(),indexWt.end());

    int currWt = indexWt[0].ff;

    rep(i,m){
        if(indexWt[i].ff==currWt){
            solve(indexWt[i].ss,indexWt[i].ff);
        }
        else{
            for(int j = i-1 ; j>=0 && indexWt[j].ff == currWt;j--){
                int ind = indexWt[j].ss;
                int u = edge[ind].ff;
                int v = edge[ind].ss;
                dpV[u] = max(dpV[u],dp[ind]);
                //cout << "OwO for " << u << " " << dpV[u] << endl;
            }
            currWt = indexWt[i].ff;
            i--;
        }
    }
    int answer =1 ;
    rep(i,m){
        answer = max(answer,dp[i]);
    }
    cout << answer << endl;
}
