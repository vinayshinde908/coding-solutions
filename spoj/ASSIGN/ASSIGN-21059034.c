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
int mask;
int arr[100][100];
int n;
ll dp[21][1<<20];
ll func(int assigned, int bitmask){
    if(assigned == n ) return dp[assigned][bitmask] = 1;
    if(dp[assigned][bitmask] != -1) return dp[assigned][bitmask];
    ll res = 0;
    REP(i, n){
        if(arr[assigned][i] and !(bitmask&(1<<i))){
            int curr = bitmask|(1<<i);
            res+=func(assigned+1, curr);
        }
    }
    return dp[assigned][bitmask] = res;
}

void solve() {
    test{
        MEM(dp, -1);
        cin>>n;
        REP(i, n) REP(j, n) cin>>arr[i][j];
        mask = (1<<n)-1;
        cout<<func(0, 0)<<endl;
    };
}

