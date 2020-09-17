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




int32_t main(){
    int n,m;
    cin >> n >>  m;
    int k;
    cin >> k;

    int index = -1;
    int s = 0 ;
    int e = n*m;
    while(s<=e){
        int mid = (s+e)/2;
        int answer =0 ;
        for(int i =1 ;i <= n ; i++){
            answer += min(m,(mid-1)/i);
        }

        if(answer < k){
            s = mid+1;
            index = mid;
        }
        else{
            e = mid-1;
        }

    }

    cout <<index << endl;
}
