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

void update(int s, int e, int qs, int qe, vi &seg, vi &lazy, int index, int value)
{
    //cout << " at " << s << " " << e << endl;
    if (lazy[index] != -1)
    {
        seg[index] = max(seg[index], lazy[index]);
        if (s != e)
        {
            if (lazy[2 * index] == -1)
                lazy[2 * index] = lazy[index];
            else
                lazy[2 * index] = max(lazy[2 * index], lazy[index]);
            if (lazy[2 * index + 1] == -1)
                lazy[2 * index + 1] = lazy[index];
            else
                lazy[2 * index + 1] = max(lazy[2 * index + 1], lazy[index]);
        }
        lazy[index] = -1;
    }

    if (qs > e || qe < s)
        return;
    if (s >= qs && e <= qe)
    {
        seg[index] = max(seg[index], value);
        if (s != e)
        {
            if (lazy[2 * index] == -1)
                lazy[2 * index] = value;
            else
                lazy[2 * index] = max(lazy[2 * index], value);
            if (lazy[2 * index + 1] == -1)
                lazy[2 * index + 1] = value;
            else
                lazy[2 * index + 1] = max(lazy[2 * index + 1], value);
        }
        return;
    }
    int mid = (s + e) / 2;
    update(s, mid, qs, qe, seg, lazy, 2 * index, value);
    update(mid + 1, e, qs, qe, seg, lazy, 2 * index + 1, value);
}

int query(int s, int e, int qs, int qe, vi &seg, vi &lazy, int index)
{
    //cout << " at " << s << " " << e << endl;
    if (lazy[index] != -1)
    {
        seg[index] = max(seg[index], lazy[index]);
        if (s != e)
        {
            if (lazy[2 * index] == -1)
                lazy[2 * index] = lazy[index];
            else
                lazy[2 * index] = max(lazy[2 * index], lazy[index]);
            if (lazy[2 * index + 1] == -1)
                lazy[2 * index + 1] = lazy[index];
            else
                lazy[2 * index + 1] = max(lazy[2 * index + 1], lazy[index]);
        }
        lazy[index] = -1;
    }

    if (qs > e || qe < s)
        return LLONG_MIN;
    if (s >= qs && e <= qe)
    {
        return seg[index];
    }
    int mid = (s + e) / 2;
    int a = query(s, mid, qs, qe, seg, lazy, 2 * index);
    int b = query(mid + 1, e, qs, qe, seg, lazy, 2 * index + 1);
    return max(a, b);
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

    string s;
    cin >> s;
    vi arr;
    int n = s.length();
    rep(i, n)
    {
        if (s[i] == '#')
            arr.pb(i);
    }
    int open = 0;
    int close = 0;
    for (auto node : s)
    {
        if (node == '(')
            open++;
        else if (node == ')')
            close++;
    }
    if ((close + arr.size()) > open)
    {
        cout << -1;
        return 0;
    }
    string check = "";
    rep(i, n)
    {
        if (s[i] != '#')
            check += s[i];
        else
        {
            if (i != arr[arr.size() - 1])
                check += ')';
            else
            {
                rep(x, open - close - arr.size() + 1) check += ')';
            }
        }
    }

    int cnt = 0;
    for (auto node : check)
    {
        if (node == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
        {
            cout << -1;
            return 0;
        }
    }
    if (cnt != 0)
        cout << -1;
    else
    {
        rep(i, arr.size() - 1) cout << 1 << endl;
        cout << open - close - arr.size() + 1;
    }
}
