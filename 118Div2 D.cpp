//Solved
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
    float s;
    float a , b ,c;
    cin >> s;
    cin >> a >> b >> s;
    cout << fixed << setprecision(7);
    cout << (a*s)/(a+b+c) << (b*s)/(a+b+c) << (c*s)/(a+b+c);
}