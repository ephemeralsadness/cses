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

    int n, x; cin >> n >> x;
    vector<pii> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> books[i].second;
    }
    sort(books.begin(), books.end());

    vector<int> dp(x + 1, -1);
    dp[0] = 0;
    int mx_cost = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = min(mx_cost, x - books[j].first); i >= 0; --i) {
            if (dp[i] >= 0) {
                dp[i + books[j].first] = max(dp[i + books[j].first], dp[i] + books[j].second);
            }
        }
        mx_cost += books[j].first;
    }

    int mx = 0;
    for (int i = 0; i <= x; ++i) {
        mx = max(mx, dp[i]);
    }

    cout << mx << endl;

    return 0;
}
