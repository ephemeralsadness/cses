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
    ll cur = 5;
    ll sm = 0;
    while (cur <= n) {
        sm += (n / cur);
        cur *= 5;
    }

    cout << sm << endl;

    return 0;
}
