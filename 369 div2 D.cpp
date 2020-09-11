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


map<int,list<int>> adj;
map<int,list<int>> inv;

int mpow(int a,int b){
    if(b ==0 ) return 1;
    int x = mpow(a,b/2);

    x = (x*x)%mod;
    if(b%2 == 1 ){
        x = (x*a)%mod;
    }
    return x;
}

void dfs1(int node,int par,stack<int> &s,map<int,bool> &visited){
    if(visited[node] == true) return;

    visited[node] = true;
    for(auto child : adj[node]){
        if(visited[child] == false){
            dfs1(child,node,s,visited);
        }

    }
    s.push(node);
}

void dfs2(int node,int par,map<int,bool> &visited,int &num){
    visited[node] = true;
    num++;
    for(auto child : inv[node]){
        if(child == par) continue;
        if(visited[child] == false){
            dfs2(child,node,visited,num);
        }
    }
}

void solve(int n ){
    stack<int> s;
    map<int,bool> visited;
    for(int i = 1 ; i <= n ; i++){
        if(visited[i] == true) continue;
        dfs1(i,i,s,visited);
    }
    visited.clear();
    int answer = 1 ;
    int leftNode = n;
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        if(visited[curr] == true) continue;
        int same = 0;
        dfs2(curr,curr,visited,same);
        if(same == 1 ) continue;
        leftNode -= same;
        answer = (answer * ((mpow(2,same) - 2 + mod)%mod))%mod;
    }
    answer = (answer * ((mpow(2,leftNode))%mod))%mod;

    cout << answer << endl;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n ;


    rep(i,n){
        int x;
        cin >> x;
        adj[i+1].pb(x);
        inv[x].pb(i+1);
    }

    solve(n);


}
