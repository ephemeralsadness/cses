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
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll now = v[0];
    ll mx = now;
    for (int i = 1; i < n; ++i) {
        if (now < 0) {
            now = v[i];
        } else {
            now += v[i];
        }

        mx = max(mx, now);
    }

    cout << mx << endl;

    return 0;
}
