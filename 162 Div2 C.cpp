#SOLVED
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
const long long INF = 1e16;

// so for each index we will maintain its maximum value we will use a map for that
// we will also maintain the maximum untill now as well as its  colo

int score[100100];
bool visited[100100];

int32_t main(){
    int n,q;
    cin >> n >> q;
    vi v(n); vi c(n);
    rep(i,n) cin >> v[i];
    rep(i,n) cin >> c[i];


    while(q--){
        rep(i,100100){
            visited[i] = false;
            score[i] = 0;
        }

        vi dp(n);

        int maxValue = -INF,maxColor =-1,secMaxValue = -INF,secMaxColor =- 1;

        int a,b;
        cin >> a >> b;

        rep(i,n){
            // so first we try to find the sum with diff color prece
            int curr=b*v[i];
            if(visited[c[i]] == true){
                curr = max(curr,score[c[i]]+a*v[i]);
            }
            if(maxColor!=-1){
                if(maxColor!=c[i]){
                    curr = max(curr,maxValue+b*v[i]);
                }
                else if(secMaxColor!=-1){
                    if(secMaxColor!=c[i]){
                        curr = max(curr,secMaxValue+b*v[i]);
                    }
                }
            }
            // is that color visited ?

            dp[i] = curr;
            if(visited[c[i]] == false) score[c[i]] = curr;
            else score[c[i]] = max(score[c[i]],curr);
            visited[c[i]] = true;
            // time to chenge the hirrarachu
            if(curr >= maxValue){
                if(c[i]!=maxColor){
                    secMaxValue = maxValue;
                    secMaxColor = maxColor;
                    maxValue = curr;
                    maxColor = c[i];
                }
                else{
                    maxValue = curr;
                }
            }
            //>= ---> >
            else if(curr>secMaxValue ){
                if(c[i]!=maxColor){
                    secMaxValue = curr;
                    secMaxColor = c[i];
                }
                /*else{
                    secMaxValue = curr;
                }*/
            }
        }
        rep(i,n){
            maxValue = max(maxValue,dp[i]);
        }
        cout  << max(0LL,maxValue) << endl;
    }


}
