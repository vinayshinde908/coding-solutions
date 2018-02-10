#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <sstream>
#include <iomanip>

using namespace std;
typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPI(i, j) for(ll i=1; i<=j; i++)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define test int t; cin>>t; while(t--)
typedef vector<int> vi;
typedef vector<ll> vl;
const ll mod = 1000000007;
const int MAX = (1e9) + 3;

void solve();


int main() {
   // freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

pair<int, bool> dp[25][80][1002];

pair<int, bool> func(int oxy, int nit, int i, int n, pair<int, pair<int, int>> gas[]) {
    if (i >= n) return {0, false};
    if (oxy < 0) oxy = 0;
    if (nit < 0) nit = 0;
    if (dp[oxy][nit][i].first != -1) return dp[oxy][nit][i];

    pair<int, bool> ans = func(oxy, nit, i + 1, n, gas);

    pair<int, bool> ans1;
    if (oxy - gas[i].first <= 0 and nit - gas[i].second.first <= 0) {
        ans1.first = gas[i].second.second;
        ans1.second = true;
    } else {
        ans1.first = func(oxy - gas[i].first, nit - gas[i].second.first, i + 1, n, gas).first;
        ans1.second = func(oxy - gas[i].first, nit - gas[i].second.first, i + 1, n, gas).second;
        ans1.first += gas[i].second.second;
    }

    dp[oxy][nit][i].first = INT32_MAX / 2, dp[oxy][nit][i].second = false;
    if (ans.second) dp[oxy][nit][i].first = ans.first, dp[oxy][nit][i].second = true;
    if (ans1.second) dp[oxy][nit][i].first = min(ans1.first, dp[oxy][nit][i].first), dp[oxy][nit][i].second = true;
    return dp[oxy][nit][i];
}


void solve() {
    test {
        REP(i, 25) REP(j, 80) REP(k, 1002) dp[i][j][k].first = -1, dp[i][j][k].second = false;
        int oxy, nit;
        cin >> oxy >> nit;
        int n;
        cin >> n;
        pair<int, pair<int, int>> gas[n];
        REP(i, n) cin >> gas[i].first >> gas[i].second.first >> gas[i].second.second;
        cout << func(oxy, nit, 0, n, gas).first  << endl;
    };
}

