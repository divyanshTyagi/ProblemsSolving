#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 200006
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

void enumerateSubmasks(int m){
    // visits submasks without repetition and in descending order
    for(int s = m ;  ; s = (s-1)&m){

        if(s == 0) {
            //...
            break;
        }
    }
}

vi dp(sz,0);
vi general(sz,0);
vi children(sz,0);
map<int,int> par;
map<int,list<int>> adj;

void fillDP(int node,int parent){
    par[node] = parent;
    dp[node] = 0;
    children[node] = 1;
    for(auto child : adj[node]){
        if(child == parent) continue;
        fillDP(child,node);
        dp[node] += dp[child];
        children[node] += children[child];
    }
    dp[node] += children[node];
}


int answer = -1;

void solve(int node,int parent){
    if(node == 1) {
        answer = dp[node];
        general[node] = dp[node];
    }
    int tempAnswer = children[1];
    for(auto child : adj[node]){
        if(child!=parent){
            tempAnswer += dp[child];
        }
        else{
            tempAnswer += general[child]-dp[node]-children[node];
        }
    }

    general[node] = tempAnswer;
    answer = max(answer,general[node]);

    for(auto child : adj[node]){
        if(child == parent) continue;
        solve(child,node);
    }

}

int32_t main(){
    int n ;
    cin >> n;

    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    fillDP(1,1);
    /*for(int i = 1 ; i <= 9 ; i++) cout << dp[i] << " " << children[i] << endl;
    cout << endl;*/
    solve(1,1);

    cout << answer << endl;

}
