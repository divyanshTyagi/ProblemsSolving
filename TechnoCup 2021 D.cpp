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

int32_t main(){
    int n ;
    cin >> n ;
    vi arr(n);
    rep(i,n) cin >> arr[i];

    int steps = INT_MAX;

    for(int i= 0 ; i < n-2 ; i++){
        int temp = arr[i+1]^arr[i+2];
        if(arr[i] > temp){
            cout << 1;
            return 0;
        }
    }

    vi xr(n);
    xr[0] = arr[0];
    rep(i,n-1) xr[i+1] = arr[i+1]^xr[i];

    // size of array is at max 70 upperbound

    for(int i = 0 ; i <=n-3; i++){
        for(int j = i ; j <= n-2 ; j++){
            for(int k = j+1 ; k <= n-1 ; k++){
                // i to j exr, j+1 to k,
                int x1 = xr[j]^((i==0)?0:xr[i-1]);
                int x2 = xr[k]^xr[j];
                if(x1>x2){
                    steps  = min(steps,(j-i)+(k-j-1));
                    //cout <<" for " << i << " " << j << " " << k << " " << steps << endl;
                }
            }
        }
    }



    if(steps == INT_MAX){
        cout << -1;
    }
    else cout << steps << endl;
}
