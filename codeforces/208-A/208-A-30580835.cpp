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
#define REPI(i,j) for(int i=1; i<=j; i++)
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
    string s;
    cin>>s;
    int start=0, end=s.length()-1;
    while(start<s.length()){
        if(start+1-s.length()>2)
            if(s[start]=='W' and s[start+1]=='U' and s[start+2]=='B'){
                start+=3;
                continue;
            }
        break;
    }
    while(end >=0 and end > start){
        if(end>2)
            if(s[end]=='B' and s[end-1]=='U' and s[end-2]=='W'){ 
                end-=3;
                continue;
            }
        break;
    }
    for(int i=start ; i<=end; i++){
        bool f=false;
        while(i<=end and s[i]=='W' and s[i+1]=='U' and s[i+2]=='B'){
            f=true;
            i+=3;
        }
        if(f) { i--;cout<<" "; continue; }
        cout<<s[i];
    }
}