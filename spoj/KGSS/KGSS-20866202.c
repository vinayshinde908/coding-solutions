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

const ll N = 1e5 + 2;
ll n;
struct node {
    ll f, s;
};

struct node T[2 * N];

void build() {
    for (ll i = n - 1; i >= 0; i--)
        T[i].f = max(T[i << 1].f, T[i << 1 | 1].f), T[i].s = T[i<<1].f > T[i<<1|1].f ? T[i<<1].s: T[i<<1|1].s;
}

void modify(ll p, ll value) {
    for (T[p += n].f = value; p > 1; p >>= 1)
        T[p >>1].f = max(T[p].f, T[p^1].f), T[p>>1].s = T[p].f > T[p^1].f ? T[p].s: T[p^1].s;
}
ll idx;
ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            if(T[l].f> res){
                res=T[l].f;
                idx = T[l].s;
            }
            l++;
        }
        if (r&1) {
            r--;
            if(T[r].f> res){
                res=T[r].f;
                idx = T[r].s;
            }
        }
    }
    idx++;
    return res;
}

void solve() {
    cin>>n;
    REP(i, n) {
        ll temp;
        cin>>temp;
        T[i+n].f = temp;
        T[i+n].s = i;
    }
    build();
    ll q;
    cin>>q;
    while(q--){
        char c;
        ll l, r;
        cin>>c;
        if(c=='Q'){
            cin>>l>>r;
            ll res = query(l-1, r);
            ll t = idx;
            res += max(query(l-1, t-1), query(t, r));
            cout<<res<<endl;
        }else{
            cin>>l>>r;
            modify(l-1, r);
        }
    }
}

