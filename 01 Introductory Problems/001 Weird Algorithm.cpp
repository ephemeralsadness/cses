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
    cout << n << ' ';
    while (n != 1) {
        n = ((n & 1) ? 3 * n + 1 : n / 2);
        cout << n << ' ';
    }
    cout.flush();

    return 0;
}
