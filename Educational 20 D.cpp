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

int mpow(int a,int b,int m){
    if(b == 0 ) return 1;
    int x = mpow(a,b/2,m);
    x = (x*x)%m;
    if(b%2){
        x = (x*a)%m;
    }
    return x;
}


int32_t main(){
    int diff_lines =0 ;
    int k;
    cin >> k;
    cin.ignore(1000, '\n');
    string s;
    getline(cin,s);


   // cout << s << endl;

    string arr = s;

    int st = 1;
    int e = 1e6;
    int answer = e;
    while(st<=e){
        int mid = (st+e)/2;
        int lines = 1;
        int capacity = mid;
        int found = 0;
        bool f = true;
        int y =0 ;
        //cout << node << endl;
        for(auto c : arr){
            y++;
            found+=1;
            //cout << y << endl;
            if(c == ' ' || c== '-' || ((y == arr.length()))){
                //cout << "word " << found << " " << capacity<<endl;
                if(mid < found){
                    f = false;
                    break;
                }
                if(capacity>=found){
                    capacity-=found;
                }
                else{
                    lines+=1;
                    capacity = mid;
                    capacity-=found;
                }
                found = 0 ;
            }
        }
        if(f == false){
            st = mid+1;
            continue;
        }
        //cout << " for " << mid <<  " " << lines << endl;
        if(lines>k){
            st = mid+1;
        }
        else{
            answer = min(answer,mid);
            e = mid-1;
        }
    }

    cout << answer << endl;


}
