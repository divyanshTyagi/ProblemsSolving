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
bool comparator(pi a, pi b){
    if(a.ss!=b.ss) return a.ss < b.ss;
    return a.ff < b.ff;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vi cnt(n);
    rep(i,n) cin >> cnt[i];
    map<int,list<int>> adj;
    rep(i,m){
        int d,t;
        cin >> d>> t;
        adj[d].pb(t);
    }

    int totalSumOg = 0 ;
    for(auto node : cnt) totalSumOg += node;
    map<int,int> visited;
    int s = 1 ;
    int e =  400000;
    int minDays = e;
    while(s<=e){
        int totalSum = totalSumOg;
        int mid = (s+e)/2;
        //cout << "at " << mid << endl;
        visited.clear();
        //vector<bool> visited(n+1,false);
        vector<pi> disc;

        for(int i = mid ; i >= 1 ; i--){
            if(adj[i].size()!=0){
                int tempSum = 0;
                for(auto node : adj[i]){
                    if(visited[node]) continue;
                    visited[node] = true;
                    tempSum += cnt[node-1];
                }
                if(tempSum) disc.pb({i,tempSum});
            }
        }
        // testing
        /*for(auto node : disc) cout << node.ff << " " << node.ss  << " ";
        cout << endl;*/

        reverse(disc.begin(),disc.end());

        int extraDays;
        int ds = disc.size();
        if(ds == 0){
            extraDays = mid;
            if((extraDays/2)>=totalSum){
                minDays = mid;
                e = mid-1;
                continue;
            }
            else{
                s = mid+1;
                continue;
            }
        }
        extraDays = mid - disc[ds-1].ff;
        for(int i = ds-1 ; i >= 0 ; i--){
            if(i == 0){
                int temp_days = disc[i].ff;
                if(temp_days>=disc[i].ss){
                    extraDays += temp_days - disc[i].ss;
                    totalSum -= disc[i].ss;
                }
                else{
                    totalSum -= temp_days;
                }
            }
            else{
                int temp_days = disc[i].ff - disc[i-1].ff;
                if(temp_days>=disc[i].ss){
                    extraDays += temp_days - disc[i].ss;
                    totalSum -= disc[i].ss;
                }
                else{
                    totalSum -= temp_days;
                    disc[i-1].ss += disc[i].ss - temp_days;
                }
            }
        }
        totalSum -= extraDays/2;
        if(totalSum <= 0) {
            minDays = mid;
            e = mid-1;
        }
        else s = mid+1;

    }
    cout << minDays << endl;



}
