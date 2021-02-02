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

    const int lim = 1000 * 1000 * 1000 + 1;
    vector<int> seq(n + 1, lim);

    for (int i = 0; i < n; ++i) {
        *lower_bound(seq.begin(), seq.end(), v[i]) = v[i];
    }

    int ans = 0;
    while (seq[ans] != lim) ++ans;
    cout << ans << endl;

    return 0;
}
