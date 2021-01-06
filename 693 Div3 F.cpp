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

int mpow(int a,int b,int m){
    if(b == 0 ) return 1;
    int x = mpow(a,b/2,m);
    x = (x*x)%m;
    if(b%2){
        x = (x*a)%m;
    }
    return x;
}
bool comparator(pi a, pi b){
    if(a.ss!=b.ss) return a.ss < b.ss;
    return a.ff < b.ff;
}

int32_t main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,m;
        cin >>n >> m;
        vector<pi> points;
        rep(i,m){
            int r,c;
            cin >> r >> c;
            points.pb({r,c});
        }
        sort(points.begin(),points.end(),comparator);

        if(m%2) {
            cout << "NO" << endl;
            continue;
        }

        bool f = true;

        for(int i =0 ; i < m-1 ; i++){

            pi f1 = points[i];
            pi f2 = points[i+1];
            if(f1.ss == f2.ss) {
                i++;
                continue;
            }
            if(f1.ff!=f2.ff){
                if(i<m-2 && points[i+2].ss == points[i+1].ss){
                    f = false;
                    break;
                }
                // we look at the differect
                int diff = f2.ss - f1.ss;
                if((diff%2) == 0){
                    i++;
                    continue;
                }
                else{
                    f = false;
                    break;
                }
            }
            else{
                if(i<m-2 && points[i+2].ss == points[i+1].ss){
                    f = false;
                    break;
                }
                int diff = f2.ss - f1.ss;

                if(diff%2){
                    i++;
                    continue;
                }
                else{
                    f = false;
                    break;
                }
            }
        }

        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;




    }


}
