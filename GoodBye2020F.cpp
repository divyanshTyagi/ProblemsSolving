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


class DisjointSet{ public:

    vector<int> parent;

    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }

    void join(int a, int b) { parent[find(b)] = find(a); }

    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b){ return find(a) == find(b); }
};






int32_t main(){
    int n,m;
    cin >> n >> m ;
    DisjointSet dsu(m+2);
    vi indices;
    int cnt =0 ;
    rep(i,n){
        int id;
        cin >> id;
        int x,y;
        if(id == 1){
            cin >> x;

            if(dsu.check(x,m+1)){
                continue;
            }

            dsu.join(x,m+1);
            indices.pb(i+1);
            cnt++;
        }
        else{

            cin >> x >> y;
            if(dsu.check(x,y)) continue;
            dsu.join(x,y);
            indices.pb(i+1);
            cnt++;
        }
    }
    cout << (mpow(2,cnt,mod)%mod) << " " << cnt << endl;
    for(auto node : indices) cout << node <<" " ;


}
