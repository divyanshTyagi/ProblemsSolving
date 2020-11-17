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
    int n ,m ;
    cin >> n >> m;

    vvi labels(m,vi(26,0));

    rep(i,n){
        string s;
        cin >> s;
        rep(i,m){
            labels[i][s[i]-'A'] = 1;
        }
    }

    int answer = 1;
    rep(i,m){
        int temp = 0;
        rep(j,26){
            if(labels[i][j]==1) temp++;
        }

        //cout << "for " << i << " " << temp << endl;
        answer = (answer*temp)%mod;
    }
    cout << answer ;

}
