#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 1000001
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

//dp[i] = summation(dp[j] + subset[j]*(arr[i]-arr[j]))
//(1+arr[i])*(all_subsets) - summation(arr[j]*subset[j])

vi maxs(sz,0);
vi mins(sz,0);
vi maxsum(sz,0);
vi minsum(sz,0);
int32_t main(){
    int n;
    cin >> n;
    vi arr(n);
    rep(i,n) cin >> arr[i];
    stack<pi> s;
    for(int i = n-1 ; i >=0 ; i--){
        while(!s.empty() && s.top().ff<arr[i]){
            s.pop();
        }
        if(!s.empty()){
            maxs[i] = s.top().ss;
        }
        else{
            maxs[i] = n;
        }
        s.push({arr[i],i});
    }

    while(!s.empty()) s.pop();

    for(int i = n-1 ; i >=0 ; i--){
        while(!s.empty() && s.top().ff>arr[i]){
            s.pop();
        }
        if(!s.empty()){
            mins[i] = s.top().ss;
        }
        else{
            mins[i] = n;
        }
        s.push({arr[i],i});
    }


    for(int i = n-1 ; i >= 0 ; i--){
        if(maxs[i]!=n){
            int temp = arr[i]*(maxs[i] - i) + maxsum[maxs[i]];
            maxsum[i] = temp;
        }
        else{
            maxsum[i] = arr[i]*(n-i);
        }
    }

    for(int i = n-1 ; i >= 0 ; i--){
        if(mins[i]!=n){
            int temp = arr[i]*(mins[i] - i) + minsum[mins[i]];
            minsum[i] = temp;
        }
        else{
            minsum[i] = arr[i]*(n-i);
        }
    }

    int answer =0 ;
    //rep(i,n) cout << minsum[i] << " ";
    //cout << endl;
    //rep(i,n) cout << maxsum[i] << " ";
    rep(i,n) answer += (maxsum[i] - minsum[i]);

    cout << answer << endl;



}
