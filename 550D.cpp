#include <bits/stdc++.h>
#define int long long
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

int32_t main()
{
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << "YES" << endl;
        cout << "2 1"
             << "\n"
             << "1 2" << endl;
        return 0;
    }
    if ((k - 1) % 2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    k--;
    for (int i = 1; i <= k; i += 2)
    {
        cout << i << " " << i + 1 << endl;
    }
    for (int i = k + 1; i <= 2 * k; i++)
    {
        for (int j = 1; j <= k; j++)
            cout << i << " " << j << endl;
        cout << i << " " << 2 * k + 1 << " ";
    }
    cout << 2 * k + 1 << " " << 2 * k + 2 << endl;
    for (int i = 2 * k + 3; i <= 3 * k + 2; i++)
        cout << 2 * k + 2 << " " << i << endl;
    for (int i = 3 * k + 3; i <= 4 * k + 2; i += 2)
    {
        cout << i << " " << i + 1 << endl;
    }
    for (int i = 2 * k + 3; i <= 3 * k + 2; i++)
    {
        for (int j = 3 * k + 3; j <= 4 * k + 2; j++)
            cout << i << " " << j << endl;
    }
}