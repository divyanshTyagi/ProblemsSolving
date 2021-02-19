#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
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

float eps = 1e-9;

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

float getRadius(float x, float y, float x1)
{
    return ((x * x + x1 * x1 - 2 * x1 * x + y * y) / (2 * y));
}

float getMinRadius(vector<pair<float, float>> &points, float x)
{
    float radius = 0;
    for (auto node : points)
    {
        float temp = getRadius(node.ff, node.ss, x);
        //cout << " for " << node.ff << " " << node.ss << " " << x << " " << temp << endl;
        if (temp < 0)
            temp *= -1;
        radius = max(radius, temp);
    }
    return radius;
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
    vector<pair<float, float>> points(n);
    rep(i, n) cin >> points[i].ff >> points[i].ss;
    bool neg = false;
    bool pos = false;
    for (auto node : points)
    {
        if (node.ss < 0)
        {
            if (pos == false)
                neg = true;
            else
            {
                cout << -1;
                return 0;
            }
        }

        else
        {
            if (neg && node.ss != 0)
            {
                cout << -1 << endl;
                return 0;
            }
            if (node.ss)
                pos = true;
        }
    }
    rep(i, n)
    {
        points[i].ss = max(points[i].ss, -points[i].ss);
    }
    sort(all(points));
    //for(auto node : points) cout << node.ff <<  " " << node.ss << endl;
    //cout << getMinRadius(points,.5) << endl;
    float answer = DBL_MAX;
    int steps = 100;
    float s = -1e7;
    float e = 1e7;
    while (steps--)
    {
        //cout << s << " " << e << endl;

        // ternary search basically gives us something to compare with, binary search me kiske saath compare krenge
        float leftX = (s) + (e - s) / 3;
        float rightX = (e) - (e - s) / 3;
        float r1 = getMinRadius(points, leftX);
        float r2 = getMinRadius(points, rightX);
        if (r1 < r2)
        {
            answer = min(answer, r1);
            e = rightX;
        }
        else
        {
            s = leftX;
            answer = min(answer, r2);
        }
    }
    // cout << s <<" " << e << endl;
    cout << fixed << setprecision(10);
    cout << getMinRadius(points, s) << endl;
}
