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
    ll x; cin >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    map<ll, ll> mp;
    for (int i = 0; i <= n; ++i) {
        ++mp[prefix[i]];
    }

    ll ctr = 0;
    for (int i = 0; i < n; ++i) {
        --mp[prefix[i]];
        if (mp.count(x + prefix[i]))
            ctr += mp[x + prefix[i]];
    }

    cout << ctr << endl;

    return 0;
}
