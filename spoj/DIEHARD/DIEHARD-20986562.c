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
typedef vector<int> vi;
typedef vector<ll> vl;
const ll mod = 1000000007;

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

int dp[1000][1000][3];

int func(int h, int a, int type){
    if(h<=0 || a <=0) return -1;
    if(dp[h][a][type] != -1) return dp[h][a][type];
    else{
        if(type == 0){
            return dp[h][a][type] = 1 + max(func(h-5, a-10, 1),func(h-20, a+5, 2));
        }else if(type == 1){
            return dp[h][a][type] = 1 + max(func(h+3, a+2, 0), func(h-20, a+5, 2));
        }else{
            return dp[h][a][type] = 1 + max(func(h+3, a+2, 0), func(h-5, a-10, 1));
        }
    }
}

void solve() {
    int t;
    cin>>t;
    while(t--){
        MEM(dp, -1);
        int h, a;
        cin>>h>>a;
        cout<<max(func(h, a, 0), max(func(h, a, 1), func(h, a, 2)))<<endl;
    }
}