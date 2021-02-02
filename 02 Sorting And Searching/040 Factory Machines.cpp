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

    int n, t; cin >> n >> t;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }

    // lower_bound
    ll left = 0; ll right = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000 + 1;
    ll mn = right;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll amount = 0;
        for (int i = 0; i < n && amount < t; ++i)
            amount += mid / k[i];

        if (amount < t) {
            left = mid + 1;
        } else {
            right = mid;
            mn = min(mn, mid);
        }
    }

    cout << mn << endl;

    return 0;
}
