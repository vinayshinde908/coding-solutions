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
    int n;
    cin>>n;
    int halfs = 0, quaters = 0, threes = 0;
    while(n--){
        string s;
        cin>>s;
        if(s[0] == '1' and s[2] == '2') halfs++;
        if(s[0] == '1' and s[2] == '4') quaters++;
        if(s[0] == '3' and s[2] == '4') threes++;
    }
    int res = 0;
    if(quaters)
        if(threes<=quaters){
            quaters -= threes;
        }else{
            quaters = 0;
        }
    res+=threes;
    res+=halfs/2;
    halfs = halfs %2;
    res+= quaters/4;
    quaters = quaters %4;
    if(halfs and quaters > 1) res+=2;
    else if(halfs and quaters <=1) res++;
    else if(!halfs and quaters) res++;
    cout<<res+1<<endl;
}