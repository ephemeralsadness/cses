#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1000 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    vector<pll> dp(N);
    dp[1] = {1, 1};
    for (int i = 2; i <= N; ++i) {
        dp[i] = {
                (2 * dp[i - 1].first + dp[i - 1].second) % MOD,
                (dp[i - 1].first + 4 * dp[i - 1].second) % MOD
        };
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (dp[n].first + dp[n].second) % MOD << endl;
    }

    return 0;
}
