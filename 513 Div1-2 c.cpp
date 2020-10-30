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


map<int,int> la;
map<int,int> lb;

void label(vi &arr,int n,map<int,int> &l){
    for(int i = 1 ; i <= n ; i++){
        int minVal = INT_MAX;
        for(int j = 0 ; (j+i)<=n ; j++){
            if(j==0){
                minVal = min(arr[i-1],minVal);
            }
            else minVal = min(minVal,arr[j+i-1]-arr[j-1]);
        }
        l[i] = minVal;
    }
}



int32_t main(){
    int n,m;
    cin >> n >> m;
    vi a(n);
    vi b(m);

    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    for(int i = 1; i < n ; i++) a[i]+=a[i-1];
    for(int i = 1; i < m ; i++) b[i]+=b[i-1];

    int x;
    cin >> x;


    label(a,n,la);
    label(b,m,lb);

    int maxArea = 0;
    for(auto an : la){
        for(auto bn : lb){
            if(an.ss*bn.ss <= x){
                maxArea = max(maxArea,an.ff*bn.ff);
            }
        }
    }
    cout << maxArea ;

}
