#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(i, j) rep(i, 0, j)
#define test int t; cin>>t; while(t--)
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define io  ios_base::sync_with_stdio(false);cin.tie(NULL);if(fopen("../input.txt", "r")) freopen("../input.txt", "r", stdin);

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

const ll mod = 1000000007;

int func1(int n, int i, int bitmask) {
    int res = 0;
    for (int j = i; j < n; j++) {
        if (bitmask & (1 << j)) res++;
    }
    return res;
}

int dp[5000][100];
int func(int n, int k, int bitmask = 0) {
    if(dp[bitmask][k] != -1) return dp[bitmask][k];
    if (k == 0 and func1(n, 0, bitmask) == n) {
        return dp[bitmask][k] = 1;
    }
    if (func1(n, 0, bitmask) == n) return dp[bitmask][k] = 0;
    int res = 0;
    REP(i, n) {
        if ((bitmask & (1 << i)) == 0) {
            int t = func1(n, i + 1, bitmask | (1 << i));
            if (t <= k) {
                res = res + func(n, k - t, bitmask | (1 << i));
            }
        }
    }
    return dp[bitmask][k] = res;
}


int main() {
    io
    test {
        MEM(dp, -1);
        int n, k;
        cin >> n >> k;
        cout << func(n, k) << endl;
    };
}
