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

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ap = 0;
    int bp = 0;

    int ctr = 0;
    while (ap < n && bp < m) {
        if (b[bp] - k <= a[ap] && a[ap] <= b[bp] + k) {
            ++ap; ++bp; ++ctr;
        } else if (a[ap] > b[bp]) {
            ++bp;
        } else {
            ++ap;
        }
    }

    cout << ctr << endl;

    return 0;
}
