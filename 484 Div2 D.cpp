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
    int n ;
    cin >> n;
    vi arr(n);
    rep(i,n) cin >> arr[i];

    multiset<int> minS;
    multiset<int,greater<int>>  maxS;
    stack<int> ng;
    stack<int> pg;

    vi ngv(n,0);
    vi pgv(n,0);

    map<int,int> pos;

    rep(i,n){
        pos[arr[i]] = i;
    }

    // filling the ng vector
    //ng.push(n-1);


    for(int i = n-1 ; i>=0 ; i--){
        while(!ng.empty() && arr[ng.top()]<arr[i]){
            ng.pop();
        }
        ngv[i] = n ;
        if(!ng.empty()){
            ngv[i] = ng.top();
        }
        ng.push(i);
    }

    // filling the pgv vector
    //pg.push(0);
    for(int i = 0 ; i< n ; i++){
        while(!pg.empty() && arr[pg.top()]<arr[i]){
            pg.pop();
        }
        pgv[i] = -1 ;
        if(!pg.empty()){
            pgv[i] = pg.top();
        }
        pg.push(i);
    }

    /*rep(i,n){
        cout <<pgv[i] << " ";
    }
    cout << endl;

    rep(i,n){
        cout << ngv[i] << " ";
    }
    cout << endl;*/
    int toPrint = LLONG_MAX;
    int bestAnswer = 1;

    minS.insert(n);
    maxS.insert(n);

    if(n == 1){
        cout << arr[0] + 1;
        return 0;
    }

    sort(arr.begin(),arr.end());
    for(int i = n-1 ; i >= 0 ; i--){
        int curr = arr[i];
        int idx = pos[curr];
        int nextIdx = ngv[idx];
        int prevIdx = pgv[idx];
        int d1 = nextIdx - idx - 1;
        int d2 = idx-prevIdx - 1;
        if(d1!=0){
            minS.insert(d1);
            maxS.insert(d1);
        }
        if(d2!=0){
            minS.insert(d2);
            maxS.insert(d2);
        }
        int dPrev = nextIdx - prevIdx - 1;
        minS.erase(minS.find(dPrev));
        maxS.erase(maxS.find(dPrev));
        if(*minS.begin() == *maxS.begin()){
            if(minS.size() >= bestAnswer){
                toPrint = curr;
            }
            bestAnswer = max(bestAnswer,(int)(minS.size()));
        }

    }
    int tpi;
    rep(i,n) if(arr[i] == toPrint) tpi = i;

    if(tpi == 0){
        tpi = 0;
    }
    else{
        tpi = arr[tpi-1] + 1;
    }

    cout << tpi << endl;

}
