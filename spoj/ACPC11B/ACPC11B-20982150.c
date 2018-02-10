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

struct ele{
    int type, val;
    ele(){
        type = 0;
        val = 0;
    }
};

bool cmp(struct ele a, ele b){
    return a.val < b.val;
}

void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        REP(i, n) cin>>arr[i];
        int m;
        cin>>m;
        int brr[m];
        REP(i, m) cin>>brr[i];
        struct ele e[m+n];
        REP(i, n) e[i].val = arr[i], e[i].type = 0;
        REP(i, m) e[i+n].val = brr[i], e[i+n].type = 1;
        sort(e, e+m+n, cmp);
        int res = INT32_MAX;
        REP(i, n+m-1){
            if(e[i].type != e[i+1].type){
                res = min(res, abs(e[i].val - e[i+1].val));
            }
        }
        cout<<res<<endl;
    }
}