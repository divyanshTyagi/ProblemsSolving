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

int sum = INT_MIN;
map<int,list<int>> adj;
vi mark;

pi solve(int node,int par){
    if(adj[node].size() == 1 && node!=par){
        return {mark[node],mark[node]}; // ss-> total sum , ff -> maxSum
    }

    int totalWt = mark[node];
    vector<pi> allValues;

    for(auto child : adj[node]){
        if(child == par) continue;
        pi x = solve(child,node);
        totalWt += x.ss;
        allValues.pb(x);
    }
    int n = allValues.size();
    if(allValues.size() > 1 ){
        sort(allValues.begin(),allValues.end());
        sum = max(sum,allValues[n-1].ff + allValues[n-2].ff);
    }

    int toReturn ;

    if(allValues.size()> 1 ){
        toReturn = max(totalWt,allValues[n-1].ff);
    }

    else{
        toReturn = max(totalWt,allValues[n-1].ff);
    }

    return {toReturn,totalWt};
}


int32_t main(){
    int n;
    cin >> n ;
    mark.resize(n+1);

    rep(i,n) cin >> mark[i+1];

    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n == 1){
        cout << "Impossible" << endl;
        return 0;
    }
    solve(1,1);

    if(sum == INT_MIN){
        cout << "Impossible" << endl;
    }
    else cout << sum << endl;


}
