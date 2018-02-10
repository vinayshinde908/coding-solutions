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
#define REPI(i,j) for(ll i=1; i<=j; i++)
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
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve() {
    int n, sx, sy, ex, ey;
    cin>>n;
    cin>>sx>>sy>>ex>>ey;
    string s;
    cin>>s;
    bool flag=false;
    int count=0;
    REP(i, s.length()){
        if(sx==ex and sy == ey) { flag=true; break; }
        if(s[i]=='N' and sy < ey) sy++;
        if(s[i]=='S' and sy > ey) sy--;
        if(s[i]=='E' and sx < ex) sx++;
        if(s[i]=='W' and sx > ex) sx--;
        count++;
    }
    if(sx==ex and sy == ey) { flag=true; }
    if(flag) cout<<count;
    else cout<<-1;
}