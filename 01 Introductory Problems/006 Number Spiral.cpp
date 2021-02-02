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

    int t; cin >> t;
    while (t--) {
        ll y, x; cin >> y >> x;
        ll m = max(y, x);
        if (m & 1) swap(y, x);
        if (x <= y) {
            cout << m * m - x + 1 << endl;
        } else {
            cout << m * m - x + 1 - m + y << endl;
        }
    }


    return 0;
}
