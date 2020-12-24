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

float dp[9000005][2];

void makeDP(){
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1 ; i <= 9000005 ; i++){
        dp[i][0] = 1 + dp[i-1][1];
        dp[i][1] = 2*(.5*(dp[i-1][0] + 1) + 1);
    }
}

int32_t main(){
    makeDP();
    int n;
    cin >> n ;
    vi arr(n);
    rep(i,n) cin >> arr[i];

    int steps =0 ;
    rep(j,n){
        for(int i = 0 ;i < n-1 ; i++){
            if(arr[i] > arr[i+1]){
                steps+=1;
                swap(arr[i],arr[i+1]);
            }
        }
    }
    //if(n == 2239) cout << steps << endl;
    cout << fixed ;
    cout << setprecision(10);
    cout << dp[steps][0];

}
