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


int32_t main(){
    int n,m;
    cin >> n >> m;
    vi row(n);
    vi col(m);

    rep(i,n) cin >> row[i];
    rep(i,m) cin >> col[i];

    int checker =0 ;
    for(auto node : row ) checker^=node;
    for(auto node : col) checker^=node;
    if(checker){
        cout << "NO";
        return 0;
    }

    vvi grid(n,vi(m,0));
    rep(i,n-1){
        grid[i+1][0] = row[i+1];
    }
    rep(i,m-1){
        grid[0][i+1] = col[i+1];
    }

    int exor = 0;
    rep(i,m-1) exor^=col[i+1];

    cout << "YES" << endl;
    grid[0][0] = exor^row[0];
    for(auto r : grid){
        for(auto c : r) cout << c << " ";
        cout << endl;
    }



}
