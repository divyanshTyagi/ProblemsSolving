// SOLVED
#include <bits/stdc++.h>
#define int long long
#define float double
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

int n,m;

int bSumInd[51];
int eSumInd[51];
int tSumInd[51];
int fSumInd[51];

int32_t main(){
    cin >>m >> n;
    rep(i,m){
        int sz;
        cin >> sz;
        vi temp(sz);
        int tSum =0 ;
        rep(j,sz){
            cin >> temp[j];
            tSum += temp[j];
        }

        tSumInd[i] = tSum;

        tSum =temp[sz-1] ;
        int maxESum = temp[sz-1];
        for(int i = sz-2 ; i>=0 ; i--){
            tSum += temp[i];
            maxESum = max(maxESum,tSum);
        }


        eSumInd[i] = maxESum;

        tSum = temp[0];
        int maxFsum = tSum;
        for(int i = 1 ; i < sz;i++){
            tSum+= temp[i];
            maxFsum = max(maxFsum,tSum);
        }
        fSumInd[i] = maxFsum;


        vi dp(sz,LLONG_MIN);
        dp[0] = temp[0];
        int mSum = dp[0];
        for(int j = 1 ; j < sz ; j++){
            dp[j] = max(dp[j-1]+temp[j],temp[j]);
            mSum = max(mSum,dp[j]);
        }
        bSumInd[i] =  mSum;
       // cout << bSumInd[i] << " " << fSumInd[i] << " " << eSumInd[i] << " " << tSumInd[i] << endl;
    }

    // for each array we have its best sum , its totalSum , its best end sum

    vi ind(n);
    rep(i,n){
        cin >> ind[i];
        ind[i]--;
    }
    vi dp(n,LLONG_MIN); // this stores the best sum we can obtain
    vi fromEnd(n,LLONG_MIN); // this stpres the best sum we can obtain taking some  suffix of current array

    dp[0] = bSumInd[ind[0]];
    fromEnd[0] = eSumInd[ind[0]];

    for(int i = 1; i < n ; i++){
        int id = ind[i];
        dp[i] = max(bSumInd[id],fromEnd[i-1]+fSumInd[id]);
        fromEnd[i] = max(fromEnd[i-1]+tSumInd[id],eSumInd[id]);
    }


    int answer = LLONG_MIN;
    rep(i,n ) answer = max(answer,dp[i]);

    cout << answer;


}
