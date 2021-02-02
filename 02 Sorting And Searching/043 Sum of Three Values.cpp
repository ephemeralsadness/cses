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
    ll x; cin >> x;
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j > 0; --j) {
            ll sm = v[i].first + v[j].first;
            auto k = lower_bound(v.begin(), v.begin() + j, pair<ll, int>{x - sm, 0});
            if (k != v.begin() + j && sm + k->first == x) {
                cout << k->second + 1 << ' ' << v[j].second + 1 << ' ' << v[i].second + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
