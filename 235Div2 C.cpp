// SOLVED
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
    int zero,one;
    cin >> zero >> one;
    int gaps = zero-1+2;
    if(gaps*2 < one){
        cout << - 1;
        return 0;
    }
    int innerGaps = zero-1;
    // what if we only fill the inner gaps
    if(innerGaps>0){
        if(one < innerGaps){
            cout << -1;
            return 0;
        }
        else{
            vi arr(innerGaps,0);
            rep(i,innerGaps){
                one--;
                arr[i]+=1;
            }
            rep(i,innerGaps){
                if(one){
                    one--;
                    arr[i]+=1;
                }
            }
            if(one>=2){
                cout << "11" ;
                one-=2;
            }
            for(auto node : arr){
                if(node==2) cout << "011";
                else cout << "01";
            }
            cout << 0;
            if(one==1){
                cout << "1";
            }
            else if(one==2)cout << "11";
        }
    }
    else{
        if(zero!=0){
            if(one==0) cout << "0";
            else if(one==1) cout << "10";
            else if(one==2) cout << "110";
            else if(one==3) cout << "1101";
            else cout << "11011";
        }
        else{
            while(one--){
                cout << "1";
            }
        }
    }



}
