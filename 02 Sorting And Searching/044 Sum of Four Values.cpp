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

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    map<ll, vector<pii>> sm_mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll sm = v[i] + v[j];
            auto it = sm_mp.find(x - sm);
            if (it != sm_mp.end()) {
                for (pii pos : it->second) {
                    if (i != pos.first && j != pos.first && i != pos.second && j != pos.second) {
                        cout << i + 1 << ' ' << j + 1 << ' ' << pos.first + 1 << ' ' << pos.second + 1 << endl;
                        return 0;
                    }
                }
            }
            sm_mp[sm].emplace_back(i, j);
        }
    }




    cout << "IMPOSSIBLE" << endl;
    return 0;
}
