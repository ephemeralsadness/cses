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

    int n; cin >> n;
    vector<int> dp(n + 1, 1000 * 1000 * 1000);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int m = i;
        while (m) {
            dp[i] = min(dp[i], dp[i - m % 10] + 1);
            m /= 10;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
