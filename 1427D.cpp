#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 100005
#define all(a) a.begin(), a.end()
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define debug cout << "here" << endl;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
using namespace std;

void enumerateSubmasks(int m)
{
    // visits submasks without repetition and in descending order
    for (int s = m;; s = (s - 1) & m)
    {

        if (s == 0)
        {
            //...
            break;
        }
    }
}

int mpow(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int x = mpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
    {
        x = (x * a) % m;
    }
    return x;
}
//4
//3 1 2 4
vector<string> steps;
void solve(vector<pair<int, int>> &s, int n)
{
    map<int, int> visited;
    while (1)
    {
        bool can = false;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = s[i].ff;
            if (visited[curr] == true || visited[curr + 1] == true)
                continue;
            if (curr + 1 > n)
                continue;
            visited[curr] = true;

            visited[curr + 1] = true;
            can = true;
            int loc1, loc2 = i;
            for (int j = 0; j < n; j++)
            {
                if (s[j].ff == curr + 1)
                {
                    loc1 = j;
                    break;
                }
            }
            if (loc1 > loc2)
                break;
            //cout << " for "  << curr << " " << curr+1 << " " << loc1 << " " << loc2 << endl;
            int a = 0, b = 0, c = 0, d = 0;
            vector<pair<int, int>> temp;
            for (int i = loc2 + 1; i < n; i++)
            {
                temp.pb(s[i]);
                d += s[i].ss;
            }
            for (int i = loc1 + 1; i <= loc2; i++)
            {
                temp.pb(s[i]);
                c += s[i].ss;
            }
            temp.pb(s[loc1]);
            b = s[loc1].ss;
            for (int i = 0; i < loc1; i++)
            {
                temp.pb(s[i]);
                a += s[i].ss;
            }
            s = temp;
            int p = 2;
            string x = "";
            if (a)
                p++;
            if (d)
                p++;
            x = x + to_string(p) + " ";
            if (a != 0)
                x = x + to_string(a) + " ";

            x = x + to_string(b) + " " + to_string(c) + " ";
            if (d != 0)
                x = x + to_string(d);
            steps.pb(x);
        }
        if (!can)
            break;
    }
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        //cout << " at " << i << endl;
        if (i == n - 1)
        {
            temp.pb(s[i]);
            continue;
        }
        if (s[i].ff == s[i + 1].ff - 1)
        {
            temp.pb({s[i].ff, s[i].ss + s[i + 1].ss});
            i++;
        }
        else
        {
            temp.pb(s[i]);
        }
    }
    s = temp;
    map<int, int> idx;
    for (auto node : s)
        idx[node.ff] = 1;

    int id = 1;
    for (auto node : idx)
        idx[node.ff] = id++;
    for (int i = 0; i < s.size(); i++)
    {
        s[i].ff = idx[s[i].ff];
    }
    //for(auto node : s) cout << node.ff << " "  << node.ss << endl;
    //cout << endl;
}

bool ascending(vector<pair<int, int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i].ff > arr[i + 1].ff)
            return false;
    }
    return true;
}
//vi primes;
//vi primesVisited(sz,false);
int32_t main()
{

    //    for(int i = 2 ; i < sz ; i++){
    //        if(primesVisited[i]) continue;
    //        primes.pb(i);
    //        for(int j = i*i ; j < sz ; j+=i) primesVisited[j] = true;
    //    }
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    rep(i, n) cin >> arr[i].ff;
    rep(i, n) arr[i].ss = 1;
    while (!ascending(arr))
    {
        solve(arr, arr.size());
    }
    cout << steps.size() << endl;
    for (auto node : steps)
        cout << node << endl;
}
