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

    int mx = v[0];
    ll ctr = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] > mx) {
            mx = v[i];
        } else {
            ctr += mx - v[i];
        }
    }

    cout << ctr << endl;

    return 0;
}
