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

int lcm(int a,int b,int c){
    int x = (a*b)/__gcd(a,b);
    return (c*x)/__gcd(c,x);
}

int32_t main(){
    int n;
    cin >> n;
    if(n == 1 ) {
        cout << 1 << endl;
        return 0;
    }
    if(n == 2 ){
        cout << 2 << endl;
        return 0;
    }

    int a = n ; int b = n-1 ; int c = n-2 ;

    for(int i = n-3 ; i > 0 ; i++){
        int l1 = lcm(a,b,i);
        int l2 = lcm(a,c,i);
        int l3 = lcm(b,c,i);
        int l = lcm(a,b,c);

        if(l1 > (l2) && l1>l3){
            if(l1 > l){
                c = i;
            }
        }
        else if(l2 > l3){
            if(l2 > l) b = i;
        }
        else{
            if(l3 > l ) a = i;
        }
    }

    cout << lcm(a,b,c);

}