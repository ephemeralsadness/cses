#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5;
const int M = 100;

const ll MOD = 1000 * 1000 * 1000 + 7;

ll dp[N][M];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (v[0] == 0) {
        for (int i = 0; i < m; ++i) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][v[0] - 1] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (v[i] == 0) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j < m - 1) {
                    dp[i][j] += dp[i - 1][j + 1];
                }
                dp[i][j] %= MOD;
            }
        } else {
            int j = v[i] - 1;
            dp[i][j] = dp[i - 1][j];
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j < m - 1) {
                dp[i][j] += dp[i - 1][j + 1];
            }
            dp[i][j] %= MOD;
        }
    }

    ll sm = 0;
    for (int i = 0; i < m; ++i) {
        sm = (sm + dp[n - 1][i]) % MOD;
    }

    cout << sm << endl;

    return 0;
}
