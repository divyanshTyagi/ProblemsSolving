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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0 ; i < n-1 ; i++){
        if(k == 0 ) break;
        if(s[i] != '4' || s[i+1]!='7') continue;
        if(i!=0 && ((i+1)%2) == 0 && s[i-1]=='4'){
            if(k%2==0){
                break;
            }
            s[i] = '7';
            break;
        }
        else if(i!=n-2 && ((i+1)%2)== 1 && s[i+2] == '7'){
            if(k%2==0){
                break;
            }
            s[i+1] = '4';
            break;
        }
        else{
            if((i+1)%2==0){
                s[i] = s[i+1] = '7';
            }
            else{
                s[i] = s[i+1] = '4';
            }
            k--;
        }
    }
    for(auto node : s){
        cout << node ;
    }


}