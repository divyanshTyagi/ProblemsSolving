//SOLVED
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
map<int,int> par;

int dp[100001];

int solve(int node,int parent){
    par[node] = parent;
    int children = 0 ;
    for(auto child : adj[node]){
        if(child == parent) continue;
        children += solve(child,node);
    }
    dp[node] = children;
    return dp[node]+1;
}


int32_t main(){
    vector<pair<pi,int>> edges;
    int n;
    cin >> n ;
    rep(i,n-1){
        int x,y,wt;
        cin >> x >> y >> wt;
        adj[x].pb(y);
        adj[y].pb(x);
        edges.pb({{x,y},wt});
    }



    solve(1,1);
    //cout << "Solved" << endl;
    int totalSum = 0;

    // calculating the initial average wt
    for(auto edge : edges){
        int u = edge.ff.ff;
        int v = edge.ff.ss;
        int wt = edge.ss;
        if(par[u] == v) swap(u,v);

        int uNum = n-1-dp[v];
        int vNum = 1+dp[v];

        totalSum += wt*(uNum)*(vNum);
    }
   // cout << "Total wt " << totalSum;
    int q;
    cin >> q;

    rep(i,q){
        int label,newWt;
        cin >> label >> newWt;
        int u = edges[label-1].ff.ff;
        int v = edges[label-1].ff.ss;
        int oldWt = edges[label-1].ss;

        if(par[u] == v) swap(u,v);

        int uNum = n-1-dp[v];
        int vNum = 1+dp[v];

        totalSum -= oldWt*(uNum)*(vNum);

        totalSum += newWt*(uNum)*(vNum);

        edges[label-1].ss = newWt;
       // cout << "Total sum is" << totalSum << endl;
        float expected = 3.0*((1.0*totalSum)/(.5*n*(n-1)));
        cout << fixed << setprecision(7) << expected << endl;

    }


}
