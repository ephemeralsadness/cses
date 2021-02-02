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

    int x, n; cin >> x >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    set<int> st;
    st.insert(0); st.insert(x);
    for (int i = 0; i < n; ++i) st.insert(v[i]);

    vector<int> r(n);

    int mx = *next(st.begin());
    for (auto it = next(st.begin()); it != st.end(); ++it) {
        mx = max(mx, *it - *prev(it));
    }
    r[n - 1] = mx;

    for (int i = n - 2; i >= 0; --i) {
        auto it = st.find(v[i + 1]);
        mx = max(mx, *next(it) - *prev(it));
        st.erase(it);
        r[i] = mx;
    }

    for (int i = 0; i < n; ++i) {
        cout << r[i] << ' ';
    }

    return 0;
}
