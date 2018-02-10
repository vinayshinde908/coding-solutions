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

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}


void solve() {
    int t;
    cin>>t;
    while(t--){
        int h, w;
        cin>>h>>w;
        int arr[h+1][w+1];
        memset(arr, 0, sizeof(arr));
        REP(i, h) REP(j, w) cin>>arr[i+1][j+1];
        int dp[h+1][w+2];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < h+1 ; i++){
            for(int j = 1; j<w+1; j++){
                dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1]))+arr[i][j];
            }
        }
        int res = INT32_MIN;
        REP(i, w+1) if(dp[h][i] > res) res=dp[h][i];
        cout<<res<<endl;
    }
}

