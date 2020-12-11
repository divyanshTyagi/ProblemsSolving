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
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n ;
        vi arr(n);
        vi soln(n,0);
        map<int,int> cnt;
        rep(i,n){
            cin >> arr[i];
            cnt[arr[i]]+=1;
        }
        int s =0 ; int e = n-1;

        rep(i,n){
            int id = i+1;
            if(cnt[id] ==0 || cnt[id] > 1 ){
                if(cnt[id]>1){
                    soln[i] = 1;
                }
                break;
            }
            if(arr[s] == id){
                soln[i] = 1;
                s++;
            }
            else if(arr[e] == id){
                soln[i] = 1;
                e--;
            }
            else{
                soln[i] = 1;
                bool f  = true;
                for(int j = 1 ; j <= n ; j++){
                    if(cnt[j] != 1) {
                        f = false;
                        break;
                    }
                }
                if(f) soln[n-1] = 1;
                break;
            }
        }
        reverse(soln.begin(),soln.end());
        for(auto node : soln) cout <<  node ;
        cout << endl;
    }


}
