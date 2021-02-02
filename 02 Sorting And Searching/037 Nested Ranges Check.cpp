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
    vector<pair<pii, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), [](pair<pii, int>& lhs, pair<pii, int>& rhs) {
        if (lhs.first.first == rhs.first.first) return rhs.first.second < lhs.first.second;
        return lhs.first.first < rhs.first.first;
    });

    vector<char> from(n);
    vector<char> to(n);

    int mx = v[0].first.second;
    for (int i = 1; i < n; ++i) {
        if (v[i].first.second <= mx)
            to[v[i].second] = true;
        mx = max(mx, v[i].first.second);
    }

    int mn = v[n - 1].first.second;
    for (int i = n - 2; i >= 0; --i){
        if (v[i].first.second >= mn)
            from[v[i].second] = true;
        mn = min(mn, v[i].first.second);
    }

    for (int i = 0; i < n; ++i) {
        cout << (from[i] ? 1 : 0) << ' ';
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << (to[i] ? 1 : 0) << ' ';
    }
    cout << endl;

    return 0;
}
