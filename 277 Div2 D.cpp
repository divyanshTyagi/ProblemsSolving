//SOLVED
#include <bits/stdc++.h>
#define float double
#define sz 100005
#define int long long
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
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
using namespace std;
map<pi,bool> visited;
map<int,list<int>> adj;
map<int,int> wt;

int dfs(int curr,int mn,int d,int parent){
    if(wt[curr] == wt[mn]){
        if(visited[{curr,mn}] == true) return 0;
        visited[{curr,mn}] = visited[{mn,curr}] = true;
    }
    if(wt[curr] > wt[mn] || (wt[mn] - wt[curr]) > d) return 0;

    int answer = 1 ;
    for(auto child : adj[curr]){
        if(child == parent) continue;
        //cout << "for " << curr << " " << child << endl;
        answer = ((answer%mod)*((1+dfs(child,mn,d,curr))%mod))%mod;
    }
    //cout << " at " << curr << "returning " << answer << endl;
    return answer;
}


int32_t main(){
    int d,n;
    cin >> d >> n ;
    rep(i,n) cin >> wt[i+1];

    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    int answer =0 ;
    for(int i =1  ; i <= n ; i++){
        int x = dfs(i,i,d,i);
        answer  = (answer + x)%mod;
    }

    cout << answer << endl;


}
