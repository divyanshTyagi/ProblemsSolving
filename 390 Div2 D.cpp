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

struct node{
    int a,b,c;
};

bool comparator(node a,node b){
    return a.a < b.a;
}

int answer =0 ;
int bestIndex = 0;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    bestIndex = k-1;
    vector<node> arr(n);

    rep(i,n) {cin >> arr[i].a >> arr[i].b; arr[i].c= i;}

    sort(arr.begin(),arr.end(),comparator);

    multiset<int> eP;
    rep(i,k-1){
        eP.insert(arr[i].b);
    }
    for(int i = k-1 ; i < n ; i++){
        int eL = LLONG_MAX;
        if(eP.size() != 0){
            eL = *eP.begin();
        }
        int s = arr[i].a;
        int e = min(eL,arr[i].b);

        if(answer < (e-s+1)){
            bestIndex = i ;
            answer = max(answer,e-s+1);
        }


        if(eP.size()!=0){
            eP.insert(arr[i].b);
            eP.erase(eP.begin());
        }
    }
    cout << answer  << endl;
    multiset<pi> indices;

    rep(i,k-1){
        indices.insert({arr[i].b,arr[i].c});
    }
    for(int j = k-1 ; j <bestIndex ; j++){
        indices.insert({arr[j].b,arr[j].c});
        indices.erase(indices.begin());
    }
    for(auto node : indices) cout << node.ss+1 <<  " ";
    cout << arr[bestIndex].c+1 ;
}