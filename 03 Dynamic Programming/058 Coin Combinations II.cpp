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

    ll MOD = 1000 * 1000 * 1000 + 7;
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < n; ++j) {
        for (int i = coins[j]; i <= x; ++i) {
            dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
