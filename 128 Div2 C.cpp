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




int32_t main(){
    int n,d;
    cin >> n >> d;
    int a,b;
    cin >> a >> b;

    vector<pi> client;

    rep(i,n){
        int x,y;
        cin >> x >> y;
        client.pb({a*x + b*y,i+1});
    }
    sort(client.begin(),client.end());
    vi pos;
    for(auto node : client){
        int id = node.ss; int wt = node.ff;
        if(d < wt) break;
        pos.pb(id);
        d -= wt;
    }
    cout << pos.size() << endl;
    for(auto node : pos) cout << node << " ";

}
