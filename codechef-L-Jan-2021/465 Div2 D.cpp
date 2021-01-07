#include <bits/stdc++.h>
#define float double
#define sz 100005
#define int long long
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

int solve(vi &a,vi &b, int idx,int n,int m){
    if(idx == n) return 0;

    if((a[idx]!=0 && b[idx]!=0) && a[idx] > b[idx]) return 1;
    int answer =0 ;
    if(a[idx]== 0 && b[idx] == 0){
        // total m C 2 ways
        int num = ((m*(m-1))/2)%mod;
        int den = mpow((m*m)%mod,mod-2,mod);
        answer =  (answer + ((num*den)%mod))%mod;

        den = mpow(m,mod-2,mod);
        answer = (answer + (den*solve(a,b,idx+1,n,m))%mod)%mod;
        return answer;
    }
    else if(a[idx] == 0){
        int num = m-b[idx];
        int den = mpow(m,mod-2,mod);
        answer =  (answer + ((num*den)%mod))%mod;

        den = mpow(m,mod-2,mod);
        answer = (answer + (den*solve(a,b,idx+1,n,m))%mod)%mod;
        return answer;
    }
    else if(b[idx] == 0){
        int num = a[idx]-1;
        int den = mpow(m,mod-2,mod);
        answer =  (answer + ((num*den)%mod))%mod;

        den = mpow(m,mod-2,mod);
        answer = (answer + (den*solve(a,b,idx+1,n,m))%mod)%mod;
        return answer;
    }
    else if(a[idx]<b[idx]) return 0;
    else return solve(a,b,idx+1,n,m);

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    cin >> n >> m;
    //cout << mpow(2,mod-1,mod);
    vi a(n);
    vi b(n);

    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    cout << solve(a,b,0,n,m);


}
