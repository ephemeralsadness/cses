#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 500;

const ll MOD = 2 * (1000 * 1000 * 1000 + 7);
ll dp[N * (N + 1) / 4 + 1];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; cin >> n;
    dp[0] = 1;
    int mx_sum = 0;

    if (n % 4 == 1 || n % 4 == 2) {
        cout << 0 << endl;
        return 0;
    }
    int equality = n * (n + 1) / 4;

    for (int i = 1; i <= n; ++i) {
        for (int j = min(mx_sum, equality - i); j >= 0; --j) {
            dp[j + i] = (dp[j + i] + dp[j]) % MOD;
        }
        mx_sum = min(mx_sum + i, equality);
    }

    cout << dp[equality] / 2 << endl;

    return 0;
}
