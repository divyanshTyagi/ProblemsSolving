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

class DisjointSet{ public:

    vector<int> parent;

    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }

    void join(int a, int b) { parent[find(b)] = find(a); }

    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b){ return find(a) == find(b); }
};

map<int,list<pi>> adj;


int32_t main(){

    int  n;
    cin >> n ;
    vvi grid(n,vi(n,0));
    rep(i,n) rep(j,n) cin >> grid[i][j];

    DisjointSet dsu(n);

    vector<pair<int,pi>> dist;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            dist.pb({grid[i][j],{i,j}});
        }
    }

    vvi box(n,vi(n,INT_MAX));
    rep(i,n) box[i][i] = 0;


    sort(dist.begin(),dist.end());

    for(auto node : dist){
        int wt = node.ff;
        int x = node.ss.ff; int y = node.ss.ss;

        if(dsu.check(x,y)==true){
            continue;
        }

        else{
            box[x][y] = box[y][x] = wt;
            dsu.join(x,y);
        }
    }

    int k;
    cin >>  k;
    while(k--){
        int u,v,wt;
        cin >> u >> v >> wt;
        u-- ; v--;
        box[u][v] = box[v][u] = min(wt,box[u][v]);
        grid[u][v] = grid[v][u] = min(grid[u][v],box[u][v]);

        // now we will for each node find the minlist to all its other guys
        rep(i,n) rep(j,n) grid[i][j] = grid[j][i] =  min(min(grid[i][j],grid[i][u] + grid[u][v] + grid[v][j]),grid[j][u] + grid[u][v] + grid[v][i]);

        // now we find the sum
        int sum = 0;
        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j < n; j++) sum += grid[i][j];
        }

        cout << sum/2 << " ";
    }

    // applying floyd warshall

    /*for(int p = 0 ; p < n ; p++){
        for(int i = 0;  i  < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(box[i][p] == INT_MAX || box[p][j] == INT_MAX) continue;
                box[i][j] = min(box[i][j],box[i][p] + box[p][j]);
            }
        }
    }

    // now we just have to take sum and divide by 2
    int sum =0  ;
    for(auto row : box){
        for(auto cell : row) sum += cell;
    }

    sum/=2;
    cout << sum << endl;*/





}
