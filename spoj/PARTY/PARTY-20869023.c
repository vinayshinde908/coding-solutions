#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>

using namespace std;
typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPI(i, j) for(int i=1; i<=j; i++)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vl;
const int mod = 1000000007;
const int m = 1000007;

void solve();



int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void knapsack(ll ar[], ll w[], ll n, ll c){
    ll dp[n+1][c+1];
    for(ll i=0; i<n+1; i++)
    for(ll j = 0 ; j<c+1; j++){
        if(!i || !j) dp[i][j] = 0;
        else if(w[i-1] <= j) dp[i][j] = max(dp[i-1][j], ar[i-1] + dp[i-1][j-w[i-1]]);
        else dp[i][j] = dp[i-1][j];
    }
    ll min = n;
    REP(i, c+1) if(dp[n][i] == dp[n][c]) {min = i; break;}
    cout<<min<<" "<<dp[n][c]<<endl;
}

void solve() {
    ll n,c;
    cin>>c>>n;
    while(1){
        if(n==0 and c==0) break;
        ll arr[n], w[n];
        REP(i, n) cin>>w[i], cin>>arr[i];
        knapsack(arr, w, n, c);
        cin>>c>>n;
    }
}