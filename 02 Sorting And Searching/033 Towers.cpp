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

    vector<int> towers;

    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(towers.begin(), towers.end(), v[i]);
        if (it == towers.end()) {
            towers.push_back(v[i]);
        } else {
            *it = v[i];
        }
    }

    cout << towers.size() << endl;

    return 0;
}
