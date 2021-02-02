#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 10;
const int M = 1001;
const ll MOD = 1000 * 1000 * 1000 + 7;
vector<int> transitions[1 << N];
ll dp[M][1 << N];

bool can_move(int i, int j, int n) {
    while (n > 0) {
        if (i & 1) {
            if (j & 1) {
                return false;
            }
        } else {
            if (!(j & 1)) {
                if (!(i & 2) && !(j & 2)) {
                    --n; i >>= 1; j >>= 1;
                } else {
                    return false;
                }
            }
        }

        --n; i >>= 1; j >>= 1;
    }
    return n == 0;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);


    int n, m;
    cin >> n >> m;

    if (n * m % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    int pn = (1 << n);

    for (int i = 0; i < pn; ++i) {
        for (int j = 0; j < pn; ++j) {
            if (can_move(i, j, n)) {
                transitions[i].push_back(j);
            }
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < pn; ++j) {
            if (dp[i][j]) {
                for (int a : transitions[j]) {
                    dp[i + 1][a] = (dp[i + 1][a] + dp[i][j]) % MOD;
                }
            }
        }
    }

    cout << dp[m][0] << endl;

    return 0;
}
