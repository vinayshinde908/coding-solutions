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
    map<char, bool> m;
    string s;
    cin>>s;
    int res=0;
    REP(i,s.length()){
        if(!m[s[i]]) res++;
        m[s[i]]=true;
    }
    if(res&1) cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
    return;
}