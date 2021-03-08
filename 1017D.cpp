#include <bits/stdc++.h>
#define float double
#define sz 1<<12
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
bool comparator(pi a,pi b){
    return a.ff < b.ff;
}
vi bitCount(1<<12,0);
vvi sum(1<<12,vi(101,0));
// we can precomupte bit wise sum,
//vi primes;
//vi primesVisited(sz,false);
int32_t main()
{

    //    for(int i = 2 ; i < sz ; i++){
    //        if(primesVisited[i]) continue;
    //        primes.pb(i);
    //        for(int j = i*i ; j < sz ; j+=i) primesVisited[j] = true;
    //    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    vi wt(n);
    rep(i,n) cin >> wt[i];
    rep(i,m){
        string s;
        cin >> s;
        int product = 1;
        int bitForm =0;
        for(int i = 0 ; i <n ;i++){
            if(s[i] == '1') bitForm += product;
            product*=2;
        }
        //cout << bitForm << endl;
        bitCount[bitForm] +=1;
    }
        //debug







        rep(i,1<<n){
            rep(j,1<<n){
                int value = 0;
                for(int x = 0 ; x < n ; x++){
                    int mask = 1<<x;
                    if((i&mask) == (j&mask)){
                        value += wt[x];
                        if(value>100) break;
                    }
                }
                if(value > 100) continue;
                else sum[i][value] += bitCount[j];
            }
        }
        //cout << time(NULL) - start << endl;

        rep(i,1<<n){
            for(int j = 1; j <=100 ; j++) sum[i][j] += sum[i][j-1];
        }



        while(q--){
            string st;
            int16_t k;
            cin >> st >> k;
            int product = 1;
            int bitForm =0;
            for(int i = 0 ; i <n ;i++){
                if(st[i] == '1') bitForm += product;
                product*=2;
            }
            cout << sum[bitForm][k] << "\n";
        }
}
