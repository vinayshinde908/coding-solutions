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
#define FOR(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPI(i, j) for(ll i=1; i<=j; i++)
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
const ll mod = 1000000007;
const ll m = 1000007;

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

int fun(int dp[300][300], int i, int j,  int n, int m){
    if(i>=0 and i<n and j>=0 and j<m and dp[i][j]!=-1)
    {
        return dp[i][j];
    }else{
        return INT32_MAX;
    }
}



void solve(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        string temp;
        cin>>n>>m;
        int dp[300][300];
        MEM(dp, -1);
        REP(i, n){
            cin>>temp;
            REP(j, m)
            dp[i][j] = temp[j] -'0' == 1 ? 0 :-1;
        }
        REP(i, n)
            REP(j, m){
                int x = (i-1>=0 && dp[i-1][j]!=-1)? (dp[i-1][j]+1): INT32_MAX;
                int y = (j-1>=0 && dp[i][j-1]!=-1)? (dp[i][j-1]+1):INT32_MAX;
                int z = ( (i-1>=0 && j-1>=0) && dp[i-1][j-1]!=-1)? (dp[i-1][j-1]+2):INT32_MAX;
                int res = min(x, min(y, z));
                if(res!=INT32_MAX) {
                    if(dp[i][j] != -1)
                        dp[i][j] = min(dp[i][j], res);
                    else
                        dp[i][j] = res;
                }
            }
        for(int i= n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int x = (i+1>=0 && dp[i+1][j]!=-1)? (dp[i+1][j]+1): INT32_MAX;
                int y = (j+1>=0 && dp[i][j+1]!=-1)? (dp[i][j+1]+1):INT32_MAX;
                int z = ( (i+1>=0 && j+1>=0) && dp[i+1][j+1]!=-1)? (dp[i+1][j+1]+2):INT32_MAX;
                int res = min(x, min(y, z));
                if(res!=INT32_MAX) {
                    if(dp[i][j] != -1)
                        dp[i][j] = min(dp[i][j], res);
                    else
                        dp[i][j] = res;
                }
            }
        }
        REP(i, n){
            REP(j, m) cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    }
}



