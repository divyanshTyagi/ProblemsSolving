#include <bits/stdc++.h>
#define float double
#define sz 100005
//#define int long long
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

void floyd(vvi &a, int n)
{
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                if (a[i][k] == INT_MAX || a[k][j] == INT_MAX)
                    continue;
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}

struct query
{
    int si;
    int ei;
    int change;
    int number;
    int answer;
};

bool comparator(query a, query b)
{
    return a.change < b.change;
}

bool comparatorOriginal(query a, query b)
{
    return a.number < b.number;
}

void multiply(vvi &a, vvi &b, int n)
{
    vvi temp(n, vi(n, INT_MAX));

    rep(i, n)
    {
        rep(j, n)
        {
            rep(k, n)
            {
                temp[i][j] = min(temp[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    a = temp;
    return;
}

//vi primes;
//vi primesVisited(sz,false);
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //    for(int i = 2 ; i < sz ; i++){
    //        if(primesVisited[i]) continue;
    //        primes.pb(i);
    //        for(int j = i*i ; j < sz ; j+=i) primesVisited[j] = true;
    //    }
    int n, m, r;
    cin >> n >> m >> r;
    vvi A(n, vi(n, INT_MAX));

    rep(z, m)
    {
        vvi a(n, vi(n, 0));
        rep(i, n) rep(j, n) cin >> a[i][j];
        floyd(a, n);
        rep(i, n) rep(j, n) A[i][j] = min(a[i][j], A[i][j]);
    }
    vector<query> queries(r);
    rep(i, r)
    {
        cin >> queries[i].si >> queries[i].ei >> queries[i].change;
        queries[i].number = i;
        queries[i].si--;
        queries[i].ei--;
    }

    sort(all(queries), comparator);

    vvi oldA = A;

    //    cout << endl;

    //    rep(i,n){
    //        rep(j,n) cout << A[i][j]  << " ";
    //        cout << endl;
    //    }

    int ptr = 0;
    int change = 0;
    while (ptr < r)
    {
        while (ptr < r && queries[ptr].change == change)
        {
            queries[ptr].answer = A[queries[ptr].si][queries[ptr].ei];
            ptr++;
        }
        multiply(A, oldA, n);

        change++;
    }

    sort(all(queries), comparatorOriginal);
    for (auto node : queries)
        cout << node.answer << endl;
}
