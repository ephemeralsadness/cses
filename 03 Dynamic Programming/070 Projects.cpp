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
    vector<pair<pii, pll>> v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second.first;
        v[i].second.second = 0;
    }
    int lim = 1000 * 1000 * 1000 + 1;
    v[n] = {{1000 * 1000 * 1000 + 1, 1000 * 1000 * 1000 + 1}, {0, 0}};

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        int a = v[i].first.first;
        int b = v[i].first.second;
        ll p = v[i].second.first;
        ll now = v[i].second.second;

        v[i + 1].second.second = max(v[i + 1].second.second, v[i].second.second);
        auto it = lower_bound(v.begin(), v.end(), pair<pii, pll>{{b, lim}, {lim, lim}});
        it->second.second = max(it->second.second, now + p);
    }

    cout << v[n].second.second << endl;


    return 0;
}
