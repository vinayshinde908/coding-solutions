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
    int st, et;
};
bool cmp(ele a, ele b){
    return a.et < b.et;
}
void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ele arr[n];
        REP(i, n) cin>>arr[i].st, cin>>arr[i].et;
        sort(arr, arr+n, cmp);
        int last_end = arr[0].et;
        int res = 1;
        REP(i, n){
            if(i==0) continue;
            if(arr[i].st >= last_end) res++, last_end = arr[i].et;
        }
        cout<<res<<endl;
    }
}