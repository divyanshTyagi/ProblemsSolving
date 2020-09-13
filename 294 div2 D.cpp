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
    vi wt(26);
    rep(i,26) cin >> wt[i];
    string s;
    cin >> s;
    int n = s.length();
    map<char,bool> visited;
    map<char,list<int>> pos;
    vi pref(n);
    pref[0] = wt[(s[0] - 'a')];

    for(int i = 1 ; i < s.length() ; i++){
        pref[i] = wt[s[i] - 'a'];
        pref[i] += pref[i-1];
    }

    rep(i,n){
        pos[s[i]].pb(i);
    }

    int answer = 0 ;
    for(char i = 'a' ;  i <= 'z' ; i++){

        map<int,int> cnt;
        if(visited[i] == true) continue;
        visited[i] = true;
        for(int j = n- 1; j>=0 ; j--){
            if(s[j] == i){
                answer += cnt[pref[j]];
                if(j!=0){
                    cnt[pref[j-1]]+=1;
                }
            }
        }
    }
    cout << answer << endl;


}