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
    int n;
    cin >> n;
    vi row(n, 0);
    vi col(n, 0);
    vvi a(n, vi(n, 0));
    vvi b(n, vi(n, 0));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> a[i][j];
            col[j] += a[i][j];
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> b[i][j];
            row[i] += b[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        rep(j, n) sum += a[i][j] * row[j];
    //cout << sum << endl;
    int q;
    cin >> q;
    while (q--)
    {
        char C;
        int x, y, v;
        cin >> C >> x >> y >> v;
        if (C == 'A')
        {
            //cout << row[y] << endl;
            sum -= a[x][y] * row[y] - v * row[y];
            col[y] -= a[x][y] - v;
            a[x][y] = v;
        }
        else
        {
            sum -= b[x][y] * col[x] - v * col[x];
            row[x] -= b[x][y] - v;
            b[x][y] = v;
        }
        cout << sum << endl;
    }
}
