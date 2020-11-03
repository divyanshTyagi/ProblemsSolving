// Solved
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
    int l,r;
    cin >> l >> r;
    if(l<r) swap(l,r);
    int lMax = l;
    int rMax = r;
    for(int i = 62 ; i >= 0 ; i--){
        int mask = (1LL<<i);
        int toCompare = (l^r);
        if((toCompare&mask)!=0) continue;
        // when both of them are 0
        if((mask&l)==0){
            int temp = (l|mask);
            if(temp<=lMax){
                l = temp;
                continue;
            }
            temp = (r|mask);
            if(temp <= lMax){
                r = temp;
                continue;
            }
        }
        else{
            int temp = (l^mask);
            if(temp>=rMax){
                l = temp;
                continue;
            }
            temp = (r^mask);
            if(temp >= rMax){
                r = temp;
                continue;
            }
        }
    }

    cout << (l^r);



}