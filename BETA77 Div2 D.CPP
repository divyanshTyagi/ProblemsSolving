//SOLVED
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
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
using namespace std;
#define int long long
unordered_map<int,int> dist;
unordered_map<int,list<pi>> adj;
unordered_map<int,pi> drive;

unordered_map<int,list<pi>> newg;
int n,m;

int32_t main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int x,y;
    cin >> x >> y;

    rep(i,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    rep(i,n){
        int t,c;
        cin >> t >> c;
        drive[i+1] = {t,c};
    }

    for(int i = 1 ;i <= n ; i++){
        dist[i] = LLONG_MAX;
        vector<int> length(n+1,LLONG_MAX);
        length[i]  = 0;
        int count = 0;
        priority_queue <pi, vector<pi>, greater<pi> > s;
        s.push({0,i});
        map<int,bool> visited;

        while(!s.empty()){

            pi curr = s.top();
            s.pop();
            count++;
            if(count == n) break;
            int node = curr.ss;
            visited[node] = true;
            for(auto child : adj[node]){
                if(visited[child.ff] == true) continue;
                if(length[node] + child.ss <  length[child.ff]){
                    length[child.ff] = length[node] + child.ss;
                    s.push({length[node] + child.ss,child.ff});
                }
            }
        }


        for(int j = 1  ; j <= n ; j++){
            if(j == i || length[j] > drive[i].ff) continue;
            newg[i].pb({j,drive[i].ss});
        }


    }


    dist[x] = 0;
    vector<int> length(n+1,LLONG_MAX);
    length[x]  = 0;
    int count = 0;
    priority_queue <pi, vector<pi>, greater<pi> > s;
    s.push({0,x});
    map<int,bool> visited;

    while(!s.empty()){

        pi curr = s.top();
        s.pop();
        count++;
        if(count == n) break;
        int node = curr.ss;
        visited[node] = true;
        for(auto child : newg[node]){
            if(visited[child.ff] == true) continue;
            if(length[node] + child.ss <  length[child.ff]){
                length[child.ff] = length[node] + child.ss;
                s.push({length[node] + child.ss,child.ff});
            }
        }
    }

    if(length[y] == LLONG_MAX) cout << -1 ;
    else cout << length[y];
}
