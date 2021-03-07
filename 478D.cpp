#include <bits/stdc++.h>
#define float double
#define sz 100005
#define int long long
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
unordered_map<int, int> dp;
unordered_map<int, bool> visited;
int findMaxHeight(int sum)
{
    int s = 0;
    int e = sum;
    int answer = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if ((mid * (mid + 1) / 2) <= sum)
        {
            answer = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return answer;
}
int answer = 0;
int totalBlocks;
int red;
int green;
int mh;
int a[200001];
int b[200001];
int solveNaive()
{

    return answer;
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

    cin >> red >> green;
    mh = findMaxHeight(red + green);
    totalBlocks = (mh * (mh + 1)) / 2;

    int answer = 0;
    rep(i, 200001) a[i] = b[i] = 0;

    for (int ht = 1; ht <= mh; ht++)
    {
        for (int r = 0; r <= red; r++)
        {
            int totalUsed = totalBlocks - ((ht) * (ht + 1) / 2);
            int redLeft = r;

            int greeLeft = green - (totalUsed - (red - redLeft));
            if (greeLeft > green)
                continue;
            //if(ht == 2 && r == 3) cout << greeLeft << endl;
            //cout << greeLeft << endl;

            if (greeLeft < 0)
                continue;
            if (ht != 1)
            {
                if (redLeft >= ht)
                {
                    a[r] += b[r - ht];
                }
                if (greeLeft >= ht)
                {
                    if (a[r] - mod >= -b[r])
                    {
                        a[r] = (((a[r] - mod) + b[r]) % mod + mod) % mod;
                    }
                    else
                        a[r] += b[r];
                }
                if (ht == mh)
                    answer += a[r];
            }
            else
            {
                if (redLeft >= ht)
                    a[r] += 1;
                if (greeLeft >= ht)
                    a[r] += 1;
                if (ht == mh)
                    answer += a[r];
                b[r] = a[r];
            }
        }
        for (int r = 0; r <= red; r++)
        {
            b[r] = a[r];
            a[r] = 0;
        }
    }

    //cout << mh << endl;
    cout << answer << endl;
}
