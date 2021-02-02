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

    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;

        int digits = 1;
        ll pos = 9;
        ll sm = 9;
        while (k > sm) {
            pos *= 10;
            digits++;
            sm += pos * digits;
        }
        k = k - sm + pos * digits;

        ll pow10 = 1;
        for (int i = 1; i < digits; ++i) {
            pow10 *= 10;
        }

        ll number = (k - 1) / digits;
        ll mod = (k - 1) % digits;

        cout << to_string(pow10 + number)[mod] << endl;
    }

    return 0;
}
