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

    int n; ll x; cin >> n >> x;
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (v[left].first + v[right].first == x) {
            cout << v[left].second << ' ' << v[right].second << endl;
            return 0;
        } else if (v[left].first + v[right].first < x) {
            ++left;
        } else {
            --right;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
