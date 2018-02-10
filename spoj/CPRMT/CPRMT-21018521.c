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
const int MAX = (1e9) + 3;

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve() {
    string a, b;
    while(cin>>a){
        cin>>b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b){
            cout << a << endl;
            continue;
        }
        int tamA = a.length(), tamB = b.length();
        string k="";
        for(int i=0, j=0;i<tamA && j<tamB;){
            if(a[i]==b[j]){
                k+= a[i];
                i++;
                j++;
            }else{
                while (a[i] < b[j]){
                    ++i;
                    if (i == tamA) break;
                }
                while (b[j] < a[i]){
                    ++j;
                    if (j == tamB) break;
                }
            }
        }
        cout<<k<<endl;
    }
}