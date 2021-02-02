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

    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    ll mx = -1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
    multiset<ll> sums;
    for (int i = 0; i < n; ++i) {
        if (i - a + 1 >= 0) {
            sums.insert(prefix[i - a + 1]);
        }
        if (i - b >= 0) {
            sums.erase(sums.find(prefix[i - b]));
        }
        if (!sums.empty()) {
            mx = max(mx, prefix[i + 1] - *sums.begin());
        }
    }

    cout << mx << endl;

    return 0;
}
