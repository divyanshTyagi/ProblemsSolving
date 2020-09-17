#solved
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



bool comparator(pair<pi,int> a,pair<pi,int> b){
    if(a.ff.ff != b.ff.ff) return a.ff.ff < b.ff.ff;

    return a.ff.ss > b.ff.ss;


}

map<int,list<int>> adj;


int32_t main(){
    // sort the input based on min size and state
    int n,m;
    cin >> n >> m;
    vi arr(n);
    rep(i,n) arr[i] = i-1;
    vector<pair<pi,int>> input;

    rep(i,m){
        int wt,status;
        cin >> wt >> status;
        input.pb({{wt,status},i});
    }


    sort(input.begin(),input.end(),comparator);


    // now we will go through the input

    int cycle = 0;
    int mst = 0;
    vector<pair<int,pi>> answer;
    for(auto node : input){
        int status = node.ff.ss;
        if(status == 1 ){
            adj[mst].pb(mst+1);
            adj[mst+1].pb(mst);
            answer.pb({node.ss,{mst,mst+1}});
            mst+=1;
        }
        else{
            while(arr[cycle] <= 0){
                cycle+=1;
            }
            if(cycle>mst){
                cout << -1 ;
                return 0;
            }
            answer.pb({node.ss,{cycle,arr[cycle]-1}});
            arr[cycle]-=1;

        }
    }



    sort(answer.begin(),answer.end());
    for(auto node: answer){
        cout << max(node.ss.ff,node.ss.ss)+1 << " " << min(node.ss.ss,node.ss.ff)+1 << endl;
    }





}