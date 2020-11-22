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

map<int,list<int>> adj;
map<int,bool> visited;

void solve(int node,int par,vi &allFound){
    allFound.pb(node);
    visited[node] = true;
    int count = 0 ;
    for(auto child : adj[node]){
        if(visited[child] == true) continue;
        else {
            count = 1;
            solve(child,node,allFound);
            break;
        }
    }
    if(!count){
        map<int,bool> visited2;
        for(auto child : adj[node]) visited2[child] = true;
        for(int i = 0 ; i < allFound.size();i++){
            if(visited2[allFound[i]]==true){
                cout << allFound.size()-i << endl;
                for(int j = i ; j < allFound.size() ; j++){
                    cout << allFound[j] << " ";
                }
                return;
            }
        }
    }

}


int32_t main(){
    int n,m,k;
    cin >> n  >> m >> k;

    rep(i,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi allFound;
    solve(1,1,allFound);

}