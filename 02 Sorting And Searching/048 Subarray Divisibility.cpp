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
        v[i] %= n;
        if (v[i] < 0) v[i] += n;
    }

    vector<int> mods(n);
    int md = 0;
    ++mods[md];
    for (int i = 0; i < n; ++i) {
        ++mods[md = (md + v[i]) % n];
    }

    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += (ll)mods[i] * (mods[i] - 1) / 2;
    }

    cout << sm << endl;

    return 0;
}
