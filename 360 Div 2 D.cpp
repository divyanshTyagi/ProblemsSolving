#include <bits/stdc++.h>
#define int long long
#define float double
//#define sz 1000001
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


vi primes;
int sz = 1e6 + 1;
vector<bool> val(1000001,true);
vector<int> fP(1000001,0);

int32_t main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    val[0] = 0;
    val[1] = 0;

    for(int i = 2 ; i < sz ; i++){

        if(!val[i]) continue;
        fP[i] =i;

        primes.pb(i);

        for(int j = i*i ; j < sz ; j+=i){

            if(val[j]) fP[j] = i;
            val[j] = false;

        }
    }

    vi cnt(1000001,0);


    int n,k;
    cin >> n >> k;
    vi arr(n);

    rep(i,n) cin >> arr[i];

    rep(i,n){
        int temp = arr[i];
        int currCount = 0 ;
        int currPrime = fP[temp];

        while(temp!=1){
            if(fP[temp] == currPrime){
                currCount += 1;
                temp/=currPrime;
            }
            else{
                cnt[currPrime] = max(cnt[currPrime],currCount);
                currCount = 1 ;
                currPrime = fP[temp];
                temp/=currPrime;
            }
        }

        cnt[currPrime] = max(cnt[currPrime],currCount);
    }
   // cout << cnt[2] << " " << cnt[3] << endl;

    for(auto node : primes){
        int capacity = cnt[node];
        while((k%node==0) && capacity){
            k/=node;
            capacity--;
        }
    }

    if(k == 1 ){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    // now we have got the lcm ke lie bois


}