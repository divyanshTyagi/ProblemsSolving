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

map<int,int> cnt;

int findAhead(int total){
    int s = 2 ;
    int e = (1e5)-2;

    int index;

    while(s<=e){
        int mid = (s+e)/2;
        int val = (mid*(mid-1))/2;
        if(val<=total){
            index = mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    return index;
}

int32_t main(){
    int tc;
    cin >> tc;
    while(tc--){
        cnt.clear();
        int n;
        cin >>  n;
        while(n){
            int index = findAhead(n);
            n-=((index*(index-1))/2);
            cnt[index]+=1;

        }
        vector<pi> keyIndex;
        for(auto node : cnt){
            keyIndex.pb({node.ff,node.ss});
        }
        sort(keyIndex.begin(),keyIndex.end());
        string answer;
        answer.pb('7');
        int three = 0;
        for(auto node : keyIndex){
            while(node.ff!=three){
                answer.pb('3');
                three+=1;
            }
            rep(i,node.ss){
                answer.pb('1');
            }
        }
        reverse(answer.begin(),answer.end());
        cout << answer << endl;
    }



}
