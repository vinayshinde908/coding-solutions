#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;


int power(int a,int b,int m = MOD){
    if(b == 0) return 1;
    if(b == 1) return a;
    int x = power(a,b/2,m)%m;
    x = (x*x)%m;
    if(b%2) return (x*a)%m;
    return x;
}


int n;

int dp[25][90][1050];

vi o, ni, w;

int solve(int ox, int nit, int index) {
    if(index>=n and ox<=0 and nit<=0) return 0;
    if(index>=n) return INF/2;
    if(ox <= 0 and nit <= 0) return 0;
    if(ox<=0) ox = 0;
    if(nit<=0) nit = 0;
    if(dp[ox][nit][index]!=-1) return dp[ox][nit][index];
    int answer1 = solve(ox, nit, index + 1);
    int answer2 = solve( max(ox - o[index], (int)0), max(nit - ni[index], (int)0), index + 1) + w[index];
    return dp[ox][nit][index] = min(answer1, answer2);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        for(int i = 0; i < 25; i++) {
            for(int j = 0; j < 90; j++) {
                for(int k = 0; k < 1050; k++)
                    dp[i][j][k] = -1;
            }
        }
        int oxygen, nitrogen;
        cin >> oxygen >> nitrogen ;
        int a, b, c;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            o.pb(a); ni.pb(b); w.pb(c);
        }

        cout << solve(oxygen, nitrogen, 0) << endl;

        o.clear(); ni.clear(); w.clear();
    }
}