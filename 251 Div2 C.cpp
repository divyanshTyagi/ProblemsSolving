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
    int n,k,p;
    cin >> n >> k >> p;

    vvi odd(k-p,vi(2,0));
    vvi even(p,vi(2,0));

    vi num(n);

    int oddNumbers =0 ;
    int evenNumbers =0 ;

    rep(i,n){
        cin >> num[i];
        if(num[i]%2 == 0) evenNumbers++;
        else oddNumbers++;
    }

    rep(i,k-p){
        if(oddNumbers == 0){
            cout << "NO" << endl;
            return 0;
        }
        oddNumbers-=1;
        odd[i][1] += 1;
    }

    rep(i,p){
        if(oddNumbers>=2){
            oddNumbers-=2;
            even[i][1]+=2;
        }
        else{
            if(evenNumbers == 0 ){
                cout << "NO" ;
                return 0;
            }
            evenNumbers-=1;
            even[i][0]+=1;
        }
    }

    // we might have some odd or even lleft;
    // 1 . if odd are left
    if(oddNumbers!=0){
        if(oddNumbers%2 == 0){
            if((k-p)!=0) odd[0][1] += oddNumbers;
            else even[0][1] += oddNumbers;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    if(evenNumbers!=0){
        if(p!=0) even[0][0] += evenNumbers;
        else odd[0][0] += evenNumbers;
    }

    vi oddValues;
    vi evenValue;
    int optr =0 ;
    int eptr = 0;
    for(auto node: num){
        if(node%2 == 0 ) evenValue.pb(node);
        else oddValues.pb(node);
    }

    rep(i,p){
        rep(j,even[i][0]) {
            cout << evenValue[eptr] << " ";
            eptr+=1;
        }
        rep(j,even[i][1]){
            cout << oddValues[optr] << " ";
            optr+=1;
        }
        cout << endl;
    }
    rep(i,k-p){
        rep(j,even[i][0]) {
            cout << evenValue[eptr] << " ";
            eptr+=1;
        }
        rep(j,even[i][1]){
            cout << oddValues[optr] << " ";
            optr+=1;
        }
        cout << endl;
    }

}