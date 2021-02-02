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

    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int pn = (1 << n);
    vector<pii> dp(pn, {100, 0});
    dp[0] = {0, 0};
    for (int i = 0; i < pn; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) {
                pii r;
                if (dp[i].second + w[j] <= x) {
                    r = {dp[i].first, dp[i].second + w[j]};
                } else {
                    r = {dp[i].first + 1, w[j]};
                }
                dp[i | (1 << j)] = min(dp[i | (1 << j)], r);
            }
        }
    }

    cout << dp[pn - 1].first + 1 << endl;

    return 0;
}
