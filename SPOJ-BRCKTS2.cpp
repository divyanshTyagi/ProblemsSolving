// SOlved
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

// o-> black , 1 -> white
int answer =0 ;
pi solve(int s,int e,int color,string &str,vi &labels){
    // base case
    if(s==(e-1)){
        // the width of this column sand the height are both 1
        if(color == 0) answer++;
        return {1,1};
    }
    int area =0 ;
    int width = e-s;
    int height = 1;
    for(int j =  s+1; j <= e-1 ; j++){
        if(str[j]=='('){
            pi temp = solve(j,labels[j],color^1,str,labels);
            j = labels[j];
            area += temp.ss;
            height = max(height,temp.ff);
        }
    }
    height++;
    int totalArea = height*width;
    int areaLeft = totalArea - area;

    if(color==0){
        answer += areaLeft;
    }

    return {height,totalArea};

}



int32_t main(){
    int tc;
    cin >> tc;
    while(tc--){
        answer =0 ;
        string s;
        cin >> s;

        int n = s.length();

        vi labels(n);
        stack<int> brack;

        for(int i=0 ; i < n ; i++){
            if(s[i]=='('){
                brack.push(i);
            }
            else{
                int connectedIndex = brack.top();
                labels[i] = connectedIndex;
                labels[connectedIndex] = i;
                brack.pop();
            }
        }

        for(int i =0 ; i < n; i++){
            if(s[i]=='('){
                int j = labels[i];
                solve(i,j,0,s,labels);
                i = j;
            }
        }
        cout << answer << endl;
    }


}
