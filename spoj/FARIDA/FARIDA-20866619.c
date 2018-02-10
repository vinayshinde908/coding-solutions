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


void solve() {
    ll t;
    ll ca=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        REP(i, n) cin>>arr[i];
        ll dp[2][n+1];
        memset(dp, 0, sizeof(dp));
        REP(i, n+1){
            if(i==0) continue;
            dp[0][i] = max(dp[1][i-1], dp[0][i-1]);
            dp[1][i] = dp[0][i-1] + arr[i-1];
        }
        //REP(i, n+1) cout<<dp[0][i]<<" ";
        //cout<<endl;
        //REP(i, n+1) cout<<dp[1][i]<<" ";
        //cout<<endl;
        cout<<"Case "<<ca<<": "<<max(dp[0][n], dp[1][n])<<endl;
        ca++;
    }
}

