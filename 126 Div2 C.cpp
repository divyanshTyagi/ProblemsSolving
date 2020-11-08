// SOLVED
#include <bits/stdc++.h>
//#define int long long
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


struct node{
    int hit;
    int miss;
    int points;
    string name;

    node(){
        hit = miss = points = 0 ;
    }



};

bool comparator(node a,node b){

    if(a.points!=b.points) return a.points > b.points;
    int d1 = a.hit-a.miss;
    int d2 = b.hit-b.miss;

    if(d1!=d2) return d1 > d2;

    if(a.hit!=b.hit) return a.hit > b.hit;

    return a.name < b.name;



}
map<pair<string,string>,bool> visited;
set<string> teams;
map<string,node> teamM;
int32_t main(){
    rep(i,5){
        string a,b;
        int s1,s2;
        cin >> a >> b ;
        scanf("%d:%d",&s1,&s2);
        //cout << a << " " << b << " " << s1 << " " << s2 << endl;
        teams.insert(a);
        teams.insert(b);

        visited[{a,b}] = true;
        visited[{b,a}] = true;

        teamM[a].name = a;
        teamM[b].name = b;

        if(s1>s2) teamM[a].points+=3;

        if(s2>s1) teamM[b].points+=3;

        if(s1==s2){
            teamM[a].points+=1;teamM[b].points+=1;
        }

        teamM[a].hit+=s1;
        teamM[b].hit+=s2;
        teamM[a].miss+=s2;
        teamM[b].miss+=s1;
    }
    teamM["BERLAND"].points+=3;

    int diff = INT_MAX;
    int winningGoal;
    int losingGoal;

    string opp;
    for(auto nodes : teams){
        if(nodes=="BERLAND") continue;
        if(visited[{nodes,"BERLAND"}]==false){
            opp = nodes;
            break;
        }
    }

    //cout << "Opponent is " << opp << endl;
    for(auto val : teamM){
        //cout << val.ss.name << val.ss.points << " " << val.ss.hit << " " << val.ss.miss << endl;
    }

    for(int i =1; i <= 200 ; i++){
        for(int j = 0 ; j < i ; j++){
            string our = "BERLAND";
            teamM[our].hit += i;
            teamM[our].miss += j;

            teamM[opp].hit += j;
            teamM[opp].miss += i;

            vector<node> teamVector;

            for(auto x : teamM){
                teamVector.pb(x.ss);
            }
            sort(teamVector.begin(),teamVector.end(),comparator);
            if(teamVector[0].name=="BERLAND" || teamVector[1].name == "BERLAND"){
                if((i-j)<diff){
                    diff = i-j;
                    winningGoal = i;
                    losingGoal = j;
                }
            }
            teamM[our].hit -= i;
            teamM[our].miss -= j;

            teamM[opp].hit -= j;
            teamM[opp].miss -= i;
        }
    }
    if(diff == INT_MAX){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << winningGoal << ":" << losingGoal << endl;
    }
}
