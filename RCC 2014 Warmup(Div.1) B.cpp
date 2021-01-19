#include <bits/stdc++.h>
//#define int long long
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


vector<pair<int,pi>> arr;
map<int,int> solved;
vvi dp(100,vi((1<<20),-1));
int32_t main(){
    int n,m,b;
    cin >> n >> m >>b;
    arr.resize(n);
    rep(i,n){
        int cost,monitor;
        cin >> cost >> monitor;
        int x;
        cin >> x;
        int mask =0 ;
        rep(j,x){
            int problemNumber;
            cin >> problemNumber;
            problemNumber--;
            mask = (mask|(1<<problemNumber));
        }
        solved[i] = mask;
        arr.pb({monitor,{cost,i}});
    // sorting ?
    }

    sort(arr.begin(),arr.end());
    rep(i,n){
        rep(j,(1<<m)){
            int idx = arr[i].ss.ss;
            if(j == 0){
                dp[i][j] = 0;
            }
            else{
                // to solve (bitwise of j)
                // we can solve solved[i];
                if(i == 0){
                    if((j|solved[idx]) ==  solved[idx]){
                        dp[i][j] = b*arr[i].ff + arr[i].ss.ff;
                    }
                    else{
                        dp[i][j] = -1;
                    }
                }
                else{
                    if((j|solved[idx]) == solved[idx]){
                        dp[i][j] = b*arr[i].ff + arr[i].ss.ff;
                    }
                    else{
                        int toSolve = j - (j&solved[idx]);
                        rep(k,i){
                            if(dp[k][toSolve]==-1) continue;
                            else{
                                dp[i][j] = b*arr[i].ff + arr[i].ss.ff + dp[k][toSolve] - b*arr[k].ff;
                            }
                        }
                    }
                }
            }
        }
    }
    int answer = LLONG_MAX;
    int mask = (1LL<<m);
    rep(i,n){
        if(dp[i][mask]==-1) continue;
        else answer = min(answer,dp[i][mask]);
    }
    if(answer == LLONG_MAX) cout <<-1 << endl;
    else cout << answer << endl;

}