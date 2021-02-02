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
    vector<pii> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());
    int ctr = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i].second < v[i - 1].second) ++ctr;
    }

    cout << ctr << endl;

    return 0;
}
