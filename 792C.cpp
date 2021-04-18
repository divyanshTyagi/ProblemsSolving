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

void printBinaryString(int n)
{
    vi temp;
    while (n)
    {
        if (n & 1)
            temp.pb(1);
        else
            temp.pb(0);
        n = n >> 1;
    }
    reverse(temp.begin(), temp.end());
    for (auto node : temp)
        cout << node << " ";
    cout << endl;
}

void readVector(vi &a)
{
    int n = a.size();
    rep(i, n) cin >> a[i];
}

string solve(string &a, string &b)
{
    int n = a.length();
    string answer = "";
    int id1 = 0;
    int id2 = 0;
    while (id1 < n && id2 < n)
    {
        answer += a[id1];
        if (a[id1] != b[id2])
        {
            answer += b[id2];
        }
        id1++;
        id2++;
    }
    return answer;
}

//vi primes;
//vi primesVisited(sz,false);

int dp[100001][3];

int32_t main()
{

    //    for(int i = 2 ; i < sz ; i++){
    //        if(primesVisited[i]) continue;
    //        primes.pb(i);
    //        for(int j = i*i ; j < sz ; j+=i) primesVisited[j] = true;
    //    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    string temp = "";
    for (auto node : s)
    {
        if (node != '0')
            temp += node;
    }
    bool zeroSpotted = false;
    vi arr;
    for (auto node : s)
        arr.pb(node - '0');
    int n = arr.size();
    for (auto node : arr)
        if (node == 0)
            zeroSpotted = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                if (arr[i] % 3 == j)
                {
                    dp[i][j] = 0;
                }
                else if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = -1;
                }
            }
            else
            {
                int a = dp[i - 1][((j - arr[i]) % 3 + 3) % 3];
                int b = dp[i - 1][j];
                //                if(i ==1 && j == 0) cout << a << " " << b << endl;
                if (a == -1 && b == -1)
                    dp[i][j] = -1;
                else if (a == -1)
                {
                    dp[i][j] = b + 1;
                }
                else if (b == -1)
                {
                    if (a == i && arr[i] == 0)
                        dp[i][j] = a + 1;
                    else
                        dp[i][j] = a;
                }
                else
                {
                    if (a == i && arr[i] == 0)
                        a++;
                    dp[i][j] = min(a, b + 1);
                }
            }
        }
    }

    //    rep(i,n){
    //        rep(j,3) cout << i << " " << j << " " << dp[i][j] << endl;
    //    }
    list<int> answer;
    int comp = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            if (dp[i][comp] == 0)
                answer.push_front(arr[i]);
            else if (dp[i][comp] == -1)
            {
                cout << -1;
                return 0;
            }
        }
        else
        {
            if (dp[i][comp] == dp[i - 1][((comp - arr[i]) % 3 + 3) % 3])
            {
                //                cout << " for " << i << endl;
                answer.push_front(arr[i]);
                comp = ((comp - arr[i]) % 3 + 3) % 3;
            }
            else
            {
                continue;
            }
        }
    }
    //    for(auto node : answer) cout << node << " ";
    //    cout << endl;

    if (answer.size() == 0)
    {

        if (zeroSpotted)
            cout << 0;
        else
            cout << -1;
        return 0;
    }
    bool zero = true;
    list<int> fin;

    for (auto node : answer)
    {
        if (zero == false)
            fin.push_back(node);
        else
        {
            if (node != 0)
            {
                zero = false;
                fin.push_back(node);
            }
        }
    }
    if (fin.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (auto node : fin)
        cout << node;
}
