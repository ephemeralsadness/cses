#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 500;

ll dp[N][N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int a, b; cin >> a >> b;
    dp[0][0] = 0;
    for (int i = 1; i < a; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j < b; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i < a; ++i) {
        for (int j = 1; j < b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1000 * 1000;
            for (int k = 0; k * 2 <= i; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k - 1][j] + 1);
            }
            for (int k = 0; k * 2 <= j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k - 1] + 1);
            }
        }
    }


    cout << dp[a - 1][b - 1] << endl;


    return 0;
}
