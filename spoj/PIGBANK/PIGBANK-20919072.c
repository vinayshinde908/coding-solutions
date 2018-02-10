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
const ll mod= 1000000007;
const ll m = 1000007;

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}


void solve(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int weight = b-a;
        int n;
        cin>>n;
        int w[n], val[n];
        REP(i, n) cin>>val[i], cin>>w[i];
        ll dp[weight+1];
        REP(i, weight+1) dp[i] = -1;
        dp[0] = 0;
        for(ll i = 0; i<=weight; i++)
            for(ll j =0 ; j<n; j++)
                if(w[j] <= i){
                    if(dp[i] == -1){
                        if(dp[i-w[j]] != -1){
                            dp[i] = dp[i-w[j]] + val[j];
                        }
                    }else{
                        if(dp[i-w[j]] != -1){
                            dp[i] = min(dp[i], dp[i-w[j]] + val[j]);
                        }
                    }
                }

        if(dp[weight] == -1)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[weight]<<"."<<endl;
    }
}