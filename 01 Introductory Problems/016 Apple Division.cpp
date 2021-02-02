#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int M = (1 << 20);
ll dp[M];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int m = (1 << n);

    ll sm = 0;
    for (int i = 0; i < n; ++i) sm += p[i];

    ll mn = sm;

    for (int i = 0; i < m; ++i) {
        mn = min(mn, abs(sm - 2 * dp[i]));
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) {
                dp[i | (1 << j)] = dp[i] + p[j];
            }
        }
    }

    cout << mn << endl;

    return 0;
}
