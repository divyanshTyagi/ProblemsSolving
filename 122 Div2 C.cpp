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
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void enumerateSubmasks(int m){
    // visits submasks without repetition and in descending order
    for(int s = m ;  ; s = (s-1)&m){

        if(s == 0) {
            //...
            break;
        }
    }
}



char grid[50][50];


// we will have 2500 points , we will store their indegrees

map<pi,int> deg;

void dfs(int i,int j,vector<vector<bool>> &visited,int &count,int n,int m){
    count+=1;
    visited[i][j] = true;
    rep(k,4){
        int x= dx[k] + i; int y = dy[k] + j;
        if(x<0 || x>=n || y<0 || y>=m) continue;
        if(grid[x][y] == '#' && visited[x][y]==false) dfs(x,y,visited,count,n,m);
    }
    return;
}

bool isConnnected(int n,int m){
    int count =0 ;
    vector<vector<bool>> visited(n,vector<bool>(m,0));

    bool flag = false;

    rep(i,n) {
        rep(j,m){
            if(grid[i][j] == '#'){
                flag = true;

                dfs(i,j,visited,count,n,m);
                break;
            }
        }
        if(flag) break;
    }
    if(!flag) return flag;
    // can redduct this
    int secCount =0 ;
    rep(i,n){
        rep(j,m) if(grid[i][j] == '#') secCount++;
    }
    if(secCount==count) return true;
    return false;

}
bool hasArticulate(int n,int m){

    rep(i,n){
        rep(j,m){
            if(grid[i][j] == '.') continue;
            grid[i][j] = '.';
            if(!isConnnected(n,m)) return true;
            grid[i][j] = '#';
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    rep(i,n) rep(j,m) cin >> grid[i][j];



    int totalCount = 0;
    rep(i,n){
        rep(j,m){
            if(grid[i][j] == '.') continue;
            totalCount +=1;
            deg[{i,j}] = 0;
            rep(k,4){
                int x= dx[k] + i; int y = dy[k] + j;
                if(x<0 || x>=n || y<0 || y>=m) continue;
                if(grid[x][y] == '#') deg[{i,j}]+=1;
            }
        }
    }
    if(totalCount<=2) {
        cout << -1;
        return 0;
    }
    if(hasArticulate(n,m)){
        cout << 1;
        return 0;
    }

    int answer =0 ;
        // iterated through all the values and find the maxDegree Index
    rep(i,n){
        rep(j,m){
            if(grid[i][j] == '#'){
                if(deg[{i,j}]==1 && totalCount!=2){
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }
    rep(i,n){
        rep(j,m){
            if(grid[i][j] == '#'){
                if(deg[{i,j}]==2 && totalCount!=3){
                    cout << 2 << endl;
                    return 0;
                }
            }
        }
    }
    rep(i,n){
        rep(j,m){
            if(grid[i][j] == 3 &&  totalCount!=4){
                if(deg[{i,j}]==3){
                    cout << 3 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;



}
