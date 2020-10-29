//SOLVED
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

vector<pi> arr;
int dp[100001][2][2];
int n;
//dp[i][j][k][l] -> at the ith index number of ways to end here with j parity and number starting with k number

int oddAnswer =0 ;
int evenAnswer =0 ;
void solve(){
    rep(i,n){
        rep(j,2){
            rep(k,2){
                // base case
                if(i == 0){
                    if(arr[i].ss!=k){
                        dp[i][j][k] = 0;
                        continue;
                    }
                    int x = arr[i].ff;
                    int odd,even;
                    if(x%2==0){
                        odd = ((x)*(x/2 + 1))/2;
                        even = (x*(x+1))/2 - odd;
                    }
                    else{
                        int terms = (x-1)/2 + 1;
                        //n + n-2 + n-4 + ...1
                        //odd = 0 + 2 + ... n-1
                        odd = (terms*(x+1))/2;
                        even = (x*(x+1))/2 - odd;
                    }

                    if(j%2==0){ dp[i][j][k] = x/2; evenAnswer += even;}
                    else {dp[i][j][k] = (x - (x/2)); oddAnswer+=odd;}
                }

                //
                if(i!=0){
                    dp[i][j][k] = 0;
                    if(k==arr[i].ss){
                        int x = arr[i].ff;
                        int odd,even;
                        if(x%2==0){
                            odd = ((x)*(x/2 + 1))/2;
                            even = (x*(x+1))/2 - odd;
                        }
                        else{
                            int terms = (x-1)/2 + 1;
                            //n + n-2 + n-4 + ...1
                            //odd = 0 + 2 + ... n-1
                            odd = (terms*(x+1))/2;
                            even = (x*(x+1))/2 - odd;
                        }
                        if(j==0){
                            evenAnswer += dp[i-1][0][k^1]*(x/2) + dp[i-1][1][k^1]*((x) - x/2) + even;
                            dp[i][j][k] += dp[i-1][j^1][k^1];
                        }
                        else{
                            dp[i][j][k] += dp[i-1][j^1][k^1];
                            if(j%2==1){
                                dp[i][j][k]++;
                            }
                            oddAnswer += dp[i-1][1][k^1]*(x/2) + dp[i-1][0][k^1]*(x-(x/2)) + odd;
                        }
                    }
                }
            }
        }
    }


}



int32_t main(){
    string s;
    cin >> s;
    n = s.length();

    int ao,ae,bo,be;
    ao = ae = bo = be =0;
    rep(i,n){
        if(s[i] == 'a'){
            if(i%2==0) ae++;
            else ao++;
        }
        else{
            if(i%2==0) be++;
            else bo++;
        }
    }

    int odd = (bo*(bo-1))/2 + (be*(be-1))/2 + (ao*(ao-1))/2 + (ae*(ae-1))/2 + n;
    int even = bo*be + ao*ae;
    cout << even << " " << odd << endl;



}
