#include <bits/stdc++.h>
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

map<int,list<pi>> adj;
int k;

vector<string> answer;

void solve(int id,vvi &labels,string &s,int &count,int &n){

    if(id == n+1){
        count+=1;
        answer.pb(s);
        return ;
    }

    for(auto edge : labels[id]){
        if(count == k) return ;
        s[edge] = '1';
        solve(id+1,labels,s,count,n);
        s[edge] = '0';
    }

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ,m;
    cin >> n >> m >> k;

    rep(i,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }

    // we do a bfs from one and find minimum distance for all nodes
    queue<int> bfs;
    bfs.push(1);

    vi dist(n+1,INT_MAX);
    dist[1] =0 ;
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();

        int cd = dist[node];

        for(auto edge : adj[node]){
            int v = edge.ff;
            if((cd+1)<dist[v]){
                dist[v] = cd+1;
                bfs.push(v);
            }
        }
    }
    // min distanve
    /*for(int i = 1 ; i<= n ; i++) cout << dist[i] <<  " ";
    cout <<endl;*/

    vvi labels(n+1);

    for(int i = 2 ; i <= n ; i++){
        for(auto edge : adj[i]){
            int oppos = edge.ff==i?edge.ss:edge.ff;
            if(dist[oppos]+1 == dist[i]) labels[i].pb(edge.ss);
        }
    }

    int count = 0;

    /*for(int i= 2; i <= n ; i++){
        cout << i << " -- ";
        for(auto node : labels[i] ) cout << node << endl;
    }*/

    string s;
    rep(i,m){
        s.pb('0');
    }

    solve(2,labels,s,count,n);

    cout << answer.size() << endl;
    for(auto s : answer) cout << s << endl;

}
