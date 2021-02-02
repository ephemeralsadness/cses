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
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    multimap<int, int> mp;
    vector<int> result(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (auto it = mp.upper_bound(v[i]); it != mp.end(); it = mp.erase(it)) {
            result[it->second] = i + 1;
        }
        mp.emplace(v[i], i);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}
