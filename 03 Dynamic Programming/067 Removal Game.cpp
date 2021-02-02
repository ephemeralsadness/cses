#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 5000;

pll dp[N][N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[0][i] = {v[i], 0};
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (dp[i - 1][j].second + v[i + j] > dp[i - 1][j + 1].second + v[j]) {
                dp[i][j] = {dp[i - 1][j].second + v[i + j], dp[i - 1][j].first};
            } else {
                dp[i][j] = { dp[i - 1][j + 1].second + v[j], dp[i - 1][j + 1].first};
            }
        }
    }
    
    cout << dp[n - 1][0].first << endl;

    return 0;
}
