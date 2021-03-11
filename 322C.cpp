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

bool repx = false;
bool repy = false;
int xf = -1;
int yf = -1;
map<int, bool> xtime;
map<int, bool> ytime;

void horizontal(char l, char r, string &s, int cor)
{
    int lc = 0, rc = 0;
    int minr = 0;
    int maxr = 0;
    int pos = 0;
    map<int, list<int>> posTimes;
    int timeToMultiply = s.length();
    posTimes[0].pb(0); // not shore if this is needed
    for (int i = 0; i < s.length(); i++)
    {
        auto node = s[i];
        if (node == l)
            lc++;
        else if (node == r)
            rc++;
        if (node == r)
            pos++;
        else if (node == l)
            pos--;
        maxr = max(maxr, pos);
        minr = min(minr, pos);
        posTimes[pos].pb(i + 1);
    }
    // we have to find the first time the cor, gets in our range;

    int st = 0;
    int et = 1e9;

    while (st <= et)
    {
        int mid = (st + et) / 2;
        int newCorPos = cor - pos * mid;
        if (newCorPos <= maxr && newCorPos >= minr)
        {
            xf = mid;
            et = mid - 1;
        }
        else if (newCorPos > maxr)
        {
            if (pos <= 0)
                et = mid - 1;
            else
                st = mid + 1;
        }
        else
        {
            if (pos <= 0)
                st = mid + 1;
            else
                et = mid - 1;
        }
    }

    if (pos == 0)
    {
        if (cor <= maxr && cor >= minr)
        {
            for (auto node : posTimes[cor])
                xtime[node] = true;
        }
        repx = true;
        return;
    }

    if (xf == -1)
        return;
    int i = xf;

    while (1)
    {
        int newCorPos = cor - pos * i;
        //cout << "new cor pos is " << newCorPos << endl;
        if (newCorPos <= maxr && newCorPos >= minr)
        {
            for (auto node : posTimes[newCorPos])
                xtime[node + i * timeToMultiply] = true;
        }
        else
            break;
        i++;
    }
}
void vertical(char l, char r, string &s, int cor)
{
    int lc = 0, rc = 0;
    int minr = 0;
    int maxr = 0;
    int pos = 0;
    int timeToMultiply = s.length();
    map<int, list<int>> posTimes;
    posTimes[0].pb(0); // not shore if this is needed
    for (int i = 0; i < s.length(); i++)
    {
        auto node = s[i];
        if (node == l)
            lc++;
        else if (node == r)
            rc++;
        if (node == r)
            pos++;
        else if (node == l)
            pos--;
        maxr = max(maxr, pos);
        minr = min(minr, pos);
        posTimes[pos].pb(i + 1);
    }
    // we have to find the first time the cor, gets in our range;

    int st = 0;
    int et = 1e9;

    while (st <= et)
    {
        int mid = (st + et) / 2;
        int newCorPos = cor - pos * mid;
        if (newCorPos <= maxr && newCorPos >= minr)
        {
            yf = mid;
            et = mid - 1;
        }
        else if (newCorPos > maxr)
        {
            if (pos <= 0)
                et = mid - 1;
            else
                st = mid + 1;
        }
        else
        {
            if (pos <= 0)
                st = mid + 1;
            else
                et = mid - 1;
        }
    }

    if (pos == 0)
    {
        if (cor <= maxr && cor >= minr)
        {
            for (auto node : posTimes[cor])
                ytime[node] = true;
        }
        repy = true;
        return;
    }
    if (yf == -1)
        return;
    int i = yf;
    while (1)
    {
        int newCorPos = cor - pos * i;

        if (newCorPos <= maxr && newCorPos >= minr)
        {
            //                cout << "Helo " << newCorPos << endl;
            //            cout << "abe " << i*timeToMultiply << endl;
            for (auto node : posTimes[newCorPos])
            { /*cout << node << " == " ;*/
                ytime[node + i * timeToMultiply] = true;
            }
        }
        else
            break;
        i++;
    }
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
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;
    if (a == 0 && b == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    horizontal('L', 'R', s, a);
    vertical('D', 'U', s, b);
    //    for(auto node : xtime) cout << node.ff <<  " " ;
    //    cout << endl;
    //    for(auto node : ytime) cout << node.ff << " ";
    //
    //    cout << endl;
    //    cout << xf << " " << yf << endl;
    //    cout << repx  << " " << repy << endl;
    if (repx && repy)
    {
        for (auto node : xtime)
        {
            for (auto n2 : ytime)
            {
                if ((n2.ff - node.ff) % s.length() == 0)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
        return 0;
    }
    else if (!repx && !repy)
    {
        for (auto node : xtime)
        {
            if (ytime[node.ff])
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    else if (repx)
    {
        for (auto node : xtime)
        {
            if (node.ff == 0)
                continue;
            for (auto n2 : ytime)
            {
                if (n2.ff % node.ff == 0)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
        return 0;
    }
    else
    {
        for (auto node : ytime)
        {
            if (node.ff == 0)
                continue;
            for (auto n2 : xtime)
            {
                if (n2.ff % node.ff == 0)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
        return 0;
    }
    //    cout << xf << endl;
    //    for(auto node : xtime) cout << node.ff << " ";
    //    cout << endl;
}
