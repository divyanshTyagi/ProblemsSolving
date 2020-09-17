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
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
using namespace std;

bool visited[501][501];
vector<pair<pi,char>> answer;
void dfs(int i,int j,int n,int m,int flag,char grid[501][501]){
    if(i>=n || j>=m || i<0 || j<0 || grid[i][j] == '#') return ;
    if(visited[i][j] == true){
        return ;
    }
    visited[i][j] = true;
    answer.pb({{i+1,j+1},'B'});
    rep(x,4){
        if(i+dx[x]>=n || j+dy[x]>=m || i+dx[x]<0 || j+dy[x]<0 || grid[i+dx[x]][j+dy[x]] == '#') continue ;
        if(visited[i+dx[x]][j+dy[x]] == true) continue;
        dfs(i+dx[x],j+dy[x],n,m,0,grid);
    }

    if(flag == 0){
        answer.pb({{i+1,j+1},'D'});
        answer.pb({{i+1,j+1},'R'});
    }

}



int32_t main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,m;
    cin >>n >> m;
    memset(visited,false,sizeof(visited));

    char grid[501][501];
    rep(i,n){
        string s;
        cin >> s;
        for(int j = 0 ; j < s.length(); j++) grid[i][j] = s[j];
    }
    rep(i,n) rep(j,m) if(visited[i][j] == false) dfs(i,j,n,m,1,grid);
    cout << answer.size() << endl;
    for(auto node : answer){
        printf("%c %d %d \n",node.ss,node.ff.ff,node.ff.ss);
    }



}