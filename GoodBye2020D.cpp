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

void enumerateSubmasks(int m){
    // visits submasks without repetition and in descending order
    for(int s = m ;  ; s = (s-1)&m){

        if(s == 0) {
            //...
            break;
        }
    }
}

int mpow(int a,int b,int m){
    if(b == 0 ) return 1;
    int x = mpow(a,b/2,m);
    x = (x*x)%m;
    if(b%2){
        x = (x*a)%m;
    }
    return x;
}

map<int,list<int>> adj;
map<int,int> deg;
priority_queue<pi> pq;



int32_t main(){
    int tc;
    cin >> tc;
    while(tc--){
        adj.clear();
        deg.clear();
        pq = priority_queue <pi>();
        int n ;
        cin >> n ;
        vi arr(n+1);
        int sum = 0 ;
        rep(i,n) {
            cin >> arr[i+1];
            sum+= arr[i+1];
        }
        rep(i,n-1){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        for(int i = 1 ; i < n+1 ; i++){
            if(deg[i]>1) pq.push({arr[i],i});
        }
        cout << sum << " ";
        for(int i = 2 ; i <n ; i++){
            if(pq.empty()){
                cout << sum << " ";
            }
            else{
                pi node = pq.top();
                pq.pop();
                deg[node.ss]--;
                cout << sum + node.ff << " ";
                sum+= node.ff;
                if(deg[node.ss]>1) pq.push({node.ff,node.ss});
            }
        }
        cout << endl;
    }


}
