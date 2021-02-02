#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100;

bool dp[N * 1000 + 1];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    int mx_sum = 0;
    dp[0] = true;
    for (int j = 0; j < n; ++j) {
        for (int i = mx_sum; i >= 0; --i) {
            if (dp[i]) {
                dp[i + coins[j]] = true;
            }
        }
        mx_sum += coins[j];
    }

    vector<int> sums;
    for (int i = 1; i <= mx_sum; ++i) {
        if (dp[i]) sums.push_back(i);
    }

    cout << sums.size() << endl;
    for (auto x : sums) {
        cout << x << ' ';
    }
    cout << endl;


    return 0;
}
