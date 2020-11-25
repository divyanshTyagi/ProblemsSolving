#include <bits/stdc++.h>

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
void build(int s,int e,int index,vector<int> &seg,vi &arr){
    if(s>e) return ;
    if(s==e){
        seg[index] =arr[s];
        return ;
    }
    int mid = (s+e)/2;
    build(s,mid,2*index,seg,arr);
    build(mid+1,e,2*index+1,seg,arr);

    int ld  = seg[2*index];
    int rd = seg[2*index+1];


    seg[index] = min(ld,rd);
}

int query(int s,int e,int qs, int qe,int index,vector<int> &seg){
    if(s>e || qs > e || qe < s){
        return INT_MAX;
    }

    if(s >= qs && e <= qe) return seg[index];

    int mid = (s+e)/2;

    int ld = query(s,mid,qs,qe,2*index,seg);
    int rd = query(mid+1,e,qs,qe,2*index+1,seg);

    return min(ld,rd);
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int n ;
        cin >> n ;
        vi arr(n);
        vector<int> seg(4*n+1);
        rep(i,n) cin >> arr[i];
        vi lMax(n);
        vi rMax(n);
        lMax[0] = arr[0];
        for(int i = 1 ; i < n ; i++) lMax[i] = max(lMax[i-1],arr[i]);

        rMax[n-1] = arr[n-1];
        for(int i = n-2 ; i>= 0 ; i--) rMax[i] = max(rMax[i+1],arr[i]);


        build(0,n-1,1,seg,arr);

        bool f = false;

        for(int i = 0 ;i < n-2 ; i++){
            if(f) break;
            int s = i+1;
            int e = n-2;

            int val = lMax[i];
            while(s<=e){
                int mid = (s+e)/2;

                int valMid = query(0,n-1,i+1,mid,1,seg);
                if(valMid < val){
                    e = mid - 1;
                    continue;
                }
                int valRight = rMax[mid+1];
                if(valRight>val){
                    s = mid+1;
                    continue;
                }
                else if(valRight < val){
                    e=  mid-1;
                    continue;
                }
                else{
                    if(valMid==val){
                        f = true;
                        cout << "YES" << endl;
                        cout << i+1 <<  " " << mid-(i+1)+1 << " " << (n-1-mid-1+1) << endl;
                        break;
                    }
                    else{
                        // vaMid > val
                        s = mid+1;
                        continue;
                    }
                }

            }
        }
        if(!f){
            cout << "NO" << endl;

            continue;
        }
    }

}

