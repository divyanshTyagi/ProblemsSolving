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

int answer =0 ;
int cycleLength = 0;

void enumerateSubmasks(int m){
    // visits submasks without repetition and in descending order
    for(int s = m ;  ; s = (s-1)&m){

        if(s == 0) {
            //...
            break;
        }
    }
}


map<int,list<int>> adj;

map<int,bool> inCycle;

void findCyclePath(int node,int par,map<int,bool> &visited,stack<int> &s,bool &flag){
    //cout <<  " AT " << node << endl;
    s.push(node);
    visited[node] = true;
    for(auto child : adj[node]){
        if(!flag) break;
        if(child == par) continue;
        if(visited[child] == true){
            cycleLength+=1;
            while(s.top()!=child){
                cycleLength+=1;
                inCycle[s.top()] = true;
                s.pop();
            }
            inCycle[child] = true;
            flag = false;
            return ;
        }
        else{
            if(flag) findCyclePath(child,node,visited,s,flag);
        }
    }
    if(flag) s.pop();
}



void solvePerNode(int node,int par,map<int,bool> &visited,int &cnt){
    //cout << " at " << node << endl;
    visited[node] = true;

    for(auto child : adj[node]){
        if(child == par || inCycle[child]) continue;
        solvePerNode(child,node,visited,cnt);


    }
    cnt+=1;
    return ;
}

int32_t main(){
    int tc;
    cin >> tc;
    while(tc--){


        adj.clear();
        inCycle.clear();
        answer =0 ;
        cycleLength = 0;


        int n;
        cin >> n ;

        rep(i,n){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        bool flag = true;
        stack<int> s;
        map<int,bool> visited;

        findCyclePath(1,1,visited,s,flag);

        visited.clear();



        // non cycle paths

        for(int i = 1 ; i <= n ; i++){
            if(inCycle[i] == false) continue;
            int cnt = 0;
            solvePerNode(i,i,visited,cnt);
            answer += (cnt*(cnt-1))/2 + (n-cnt)*(cnt);
        }

           cout << answer << endl;
    }

}
