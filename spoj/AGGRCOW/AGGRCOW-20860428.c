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

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

ll bin(ll arr[], ll n, ll c){
    ll low = 0, high = arr[n-1];
    while(low<high){
        ll mid = (low + high)/2;
        ll cows_alloted = 1;
        ll prev = arr[0];
        REP(i, n){
            if(!i) continue;
            if(arr[i] - prev >= mid){
                cows_alloted++;
                prev = arr[i];
            }
            if(cows_alloted==c) break;
        }
        if(cows_alloted == c) low = mid+1;
        else high = mid;
    }
    return low-1;
}

void solve() {
    int t;
    cin>>t;
    while(t--){
        ll n, c;
        cin>>n>>c;
        ll arr[n];
        REP(i, n){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        cout<<bin(arr, n, c)<<endl;
    }
}

