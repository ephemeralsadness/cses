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
    vector<pair<int, bool>> times(n * 2);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        times[i * 2] = {a, true};
        times[i * 2 + 1] = {b, false};
    }

    sort(times.begin(), times.end());

    int mx = 0;
    int ctr = 0;
    for (int i = 0; i < n * 2; ++i) {
        if (times[i].second) {
            ++ctr;
            mx = max(mx, ctr);
        } else {
            --ctr;
        }
    }

    cout << mx << endl;

    return 0;
}
