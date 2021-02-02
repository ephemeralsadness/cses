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

    multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int h; cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; ++i) {
        int t; cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            cout << *prev(it) << '\n';
            tickets.erase(prev(it));
        }
    }

    return 0;
}
