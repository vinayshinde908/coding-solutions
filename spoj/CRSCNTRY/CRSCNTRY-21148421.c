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


int func(int i, int j, int ar[], int br[], int n, int m, int dp[][2300]) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == n || j == m) return dp[i][j] = 0;
    if (ar[i] == br[j]) return dp[i][j] = 1 + func(i + 1, j + 1, ar, br, n, m, dp);
    else return dp[i][j] = max(func(i + 1, j, ar, br, n, m, dp), func(i, j + 1, ar, br, n, m, dp));
}

int main() {
    io
    test {
        int n = 0, m = 0, arr[2300], brr[2300], res = 0;
        int temp, i = 0;
        cin >> temp;
        while (temp) {
            n++;
            arr[i++] = temp;
            cin >> temp;
        }
        while (1) {
            i = 0, m = 0;
            cin >> temp;
            if (!temp) break;
            while (temp) {
                m++;
                brr[i++] = temp;
                cin >> temp;
            }
            int dp[n + 3][2300];
            MEM(dp, -1);
            res = max(res, func(0, 0, arr, brr, n, m, dp));
        }
        cout << res << endl;
    };
}
