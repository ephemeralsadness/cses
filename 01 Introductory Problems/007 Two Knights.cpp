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

    ll n; cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cout << (i * i * i * i - 9 * i * i + 24 * i - 16) / 2 << endl;
    }


    return 0;
}
