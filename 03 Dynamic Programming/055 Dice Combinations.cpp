#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    const ll MOD = 1000 * 1000 * 1000 + 7;
    int n; cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = max(0, i - 6); j < i; ++j) {
            dp[i] += dp[j];
        }
        dp[i] %= MOD;
    }

    cout << dp[n] << endl;

    return 0;
}
