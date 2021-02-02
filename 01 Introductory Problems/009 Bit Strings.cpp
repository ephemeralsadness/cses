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

    const ll MOD = 1e9 + 7;
    ll n; cin >> n;

    ll cur = 2;
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * cur) % MOD;
        }
        cur = (cur * cur) % MOD;
        n >>= 1;
    }

    cout << res << endl;

    return 0;
}
