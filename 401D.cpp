#include <bits/stdc++.h>
#define ll long long
#define float double
#define sz 100005
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
ll dp[1 << 18][100];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll temp = n;
    vi num;
    while (temp)
    {
        num.pb(temp % 10);
        temp /= 10;
    }
    n = num.size();
    int modVal[18];
    modVal[0] = 1;
    for (int i = 1; i < 18; i++)
        modVal[i] = (10 * modVal[i - 1]) % m;

    rep(i, 1 << n)
    {
        rep(j, m)
        {
            // dp[i][j] means that possible ways to have set bits in i waale and mod value be j
            if (i == 0)
                continue;
            if (__builtin_popcount(i) == 1)
            {
                rep(k, n)
                {
                    if (i & (1 << k))
                    {
                        int number = num[k];
                        int val = (number * modVal[0]) % m;
                        if (val == j)
                            dp[i][j] = 1;
                    }
                }
            }
            else
            {
                rep(k, n)
                {
                    if (i & (1 << k))
                    {
                        if (__builtin_popcount(i) == n && num[k] == 0)
                            continue;
                        int number = num[k];
                        int val = (number * modVal[__builtin_popcount(i) - 1]) % m;
                        int otherVal = (j - val);
                        if (otherVal < 0)
                            otherVal += m;
                        dp[i][j] = (dp[i][j] + dp[i ^ (1 << k)][otherVal]);
                    }
                }
            }
        }
    }

    vi cnt(11, 0);
    for (auto node : num)
        cnt[node]++;
    ll fact[20];
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 18; i++)
        fact[i] = (i * fact[i - 1]);
    ll den = 1;
    for (auto node : cnt)
        den = (den * fact[node]);
    //
    //
    //    rep(i,1<<n) rep(j,m) cout << i  << " " << j << " " << dp[i][j] << endl;
    cout << (dp[(1 << n) - 1][0] / den) << endl;
}
