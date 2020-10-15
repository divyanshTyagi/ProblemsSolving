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
//#define pi pair<int,int>
using namespace std;
vector<int> pi;
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    int count =0 ;
    pi.clear();
    pi.resize(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        //debug
        // incrementing the length
        int x = i+1 - pi[i];
        if(x == i+1 || x== 0) continue;
        if((i+1)%x == 0 ){
            int totalSegement = (i+1)/((i+1) - pi[i]);
            count+=1;
            cout << i+1 << " " << totalSegement << endl;
        }
    }
    if(count == 0 ) cout << endl;

}


int32_t main(){
    int tc;
    cin >> tc;
    int i = 0 ;
    while(tc--){
        i+=1;
        int n;
        cin >> n ;
        string s;
        cin >> s;
        cout << "Test case #" << i << endl;
        prefix_function(s);
    }

}
