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

    int n, m; cin >> n >> m;
    vector<pii> v(n);
    vector<int> x(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        v[i] = {x[i], i};
    }
    sort(v.begin(), v.end());

    int ctr = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i].second < v[i - 1].second) ++ctr;
    }

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;

        auto it = lower_bound(v.begin(), v.end(), pii{x[a], 0});
        auto jt = lower_bound(v.begin(), v.end(), pii{x[b], 0});

        set<int> positions;
        positions.insert(it - v.begin());
        positions.insert(it - v.begin() + 1);
        positions.insert(jt - v.begin());
        positions.insert(jt - v.begin() + 1);
        positions.erase(0);
        positions.erase(n);

        int was = 0;
        for (auto p : positions) {
            was += v[p].second < v[p - 1].second;
        }

        swap(it->second, jt->second);
        swap(x[a], x[b]);

        int become = 0;
        for (auto p : positions) {
            become += v[p].second < v[p - 1].second;
        }

        ctr += (become - was);

        cout << ctr << endl;
    }

    return 0;
}
