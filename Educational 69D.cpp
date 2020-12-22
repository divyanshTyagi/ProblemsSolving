#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 300005
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

int dp[sz];

int32_t main(){
    int n,m,k;
    cin >> n >> m >> k;

    multiset<int> minValues;
    vi arr(n);
    vi prefix(n);
    rep(i,n) cin >> arr[i];

    prefix[0] = arr[0];
    for(int i = 1 ; i < n ; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    for(int i = 0 ; i< min(m,n) ; i++){
        if(i == 0){
            dp[i] = arr[i] - k;
        }
        else{
            dp[i] = prefix[i] - *minValues.begin() - k;
            dp[i] = max(prefix[i] - k,max(dp[i],arr[i] - k));
        }
        minValues.insert(prefix[i]);
    }
    for(int i = m ; i < n ; i++){
        dp[i] = max(arr[i]-k,max(dp[i-m] - k + prefix[i] - prefix[i-m], prefix[i] - *minValues.begin() - k));
        dp[i] = max(dp[i],arr[i]-k);
        minValues.erase(minValues.find(prefix[i-m]));
        minValues.insert(prefix[i]);
    }
    int answer = 0;
    rep(i,n) answer = max(answer,dp[i]);
    cout << answer << endl;
}
