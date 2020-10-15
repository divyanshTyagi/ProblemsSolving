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

vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int findSubstring(string &source,string &toFind,vi &kmpPrefix){
    int i =0 ; int j =0 ;
    int nSource = source.length();
    int nToFind = toFind.length();
    int count = 0 ;
    while(i<nSource){
       //cout << i << " " << j << endl;

        if(source[i] == toFind[j]) {
            i++;
            j++;

            if(j == nToFind) {
                //cout << i-nToFind << endl;
                count+=1;
                j = kmpPrefix[j-1];
                if(kmpPrefix[j]!=0) i++;
              }
        }
        else{
            if(j!=0){
                j = kmpPrefix[j-1];
            }
            else i = i +1;
        }
    }
    //if(count == 0 ) cout << endl;
    return count;
}

int32_t main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n ;
        string source;
        string dest = "";
        cin >> source;
        for(int i = 1 ; i< n ; i++){
            if(s[i]>s[i-1]) source+= 'G';
            else if(s[i]<s[i-1]) source+= 'L';
            else source+='E';
        }
        vi kmpPrefix = prefix_function(dest);
        int count = findSubstring(source,dest);
        if(count!=0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
