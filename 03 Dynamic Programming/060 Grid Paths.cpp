#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;

char grid[N][N];
ll dp[N][N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == '.') {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[0][i] == '.') {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
