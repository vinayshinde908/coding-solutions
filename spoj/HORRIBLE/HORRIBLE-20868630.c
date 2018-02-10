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


const ll N = 1e6;
ll T[N],B[N];

void update1(ll T[], ll idx, ll val)
{
    while(idx<=N)
    {
        T[idx]+=val;
        idx += (idx & -idx);
    }
}
void update(ll a, ll b, ll c){
    update1(T, a, c );
    update1(T, b+1, -c);
    update1(B, a, c*(a-1));
    update1(B, b+1, -c*b);
}
ll read(ll T[],ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum += T[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
ll query(ll l,ll r)
{
    ll lef=read(T, l-1)*(l-1)-read(B , l-1);
    ll ri=read(T, r)*r - read(B, r);
    return ri-lef;
}

void solve() {
    int t;
    cin>>t;
    while(t--){
        ll n, c;
        cin>>n>>c;
        memset(T, 0, sizeof(T));
        memset(B, 0, sizeof(B));
        while(c--){
            int t;
            cin>>t;
            if(t==0){
                ll p, q, v;
                cin>>p>>q>>v;
                update(p, q, v);
            }else{
                ll p, q;
                cin>>p>>q;
                cout<<query(p, q)<<endl;
            }
        }
    }
}

