#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 100005
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define debug cout << "here" << endl;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
using namespace std;

map<int,int> dist;

pair <int,int> findDiameter(int node,int par,map<int,list<int>> &adj){
    // if we have reacher a terminal node
    if(adj[node].size() == 1 && par!=node){
        //cout << "At " << node << endl;
        return {0,1};
    }
    else{
        multiset<int,greater<int>> childDistance;
        int maxDim = 0;
        for(auto child : adj[node]){
            if(child == par) continue;
            pi temp = findDiameter(child,node,adj);
            childDistance.insert(temp.ss);
            maxDim = max(maxDim,temp.ff);
        }
        int x = 0 ; int y = 0;
        x = *childDistance.begin();
        childDistance.erase(childDistance.begin());
        if(!childDistance.empty()){
            y = *childDistance.begin();
            childDistance.erase(childDistance.begin());
        }
        //cout << x << " " << y << endl;
        maxDim = max(maxDim,x+y);
        int maxChild = 1 + max(x,y);
        return {maxDim,maxChild};
    }

}
void dfs(int node,int par,map<int,list<int>> &adj,map<int,int> &dis,int dist){
    dis[node] = dist;
    for(auto child:adj[node]){
        if(child == par) continue;
        dfs(child,node,adj,dis,dist+1);
    }
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        int n,a,b,da,db;
        cin >> n >> a >> b >> da >> db;

        map<int,list<int>> adj;
        rep(i,n-1){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        map<int,int> dis;
        int maxDiameter = findDiameter(1,1,adj).ff;
        dfs(a,a,adj,dis,0);

        if(dis[b] <= da || 2*da >= maxDiameter || db<=2*da){
            cout << "Alice" << endl;
        }
        else cout << "Bob" << endl;

    }
    return 0;
}
