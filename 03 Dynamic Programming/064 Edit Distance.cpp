#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 5001;

ll dp[N][N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    string s, t; cin >> s >> t;
    int sn = s.size();
    int tn = t.size();

    dp[0][0] = 0;
    for (int i = 1; i <= sn; ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= tn; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= sn; ++i) {
        for (int j = 1; j <= tn; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    cout << dp[sn][tn] << endl;

    return 0;
}
