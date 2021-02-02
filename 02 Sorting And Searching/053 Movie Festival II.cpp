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

    int n, k; cin >> n >> k;
    vector<pii> v(n);
    for (int i = 0; i < n;  ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](pii lhs, pii rhs) {
        if (lhs.second == rhs.second)
            return lhs.first < rhs.first;
        return lhs.second < rhs.second;
    });

    multiset<int> st;
    int ctr = 0;

    for (int i = 0; i < n; ++i) {

        auto it = st.upper_bound(v[i].first);
        if (it != st.begin()) {
            --it;
            st.erase(it);
            st.insert(v[i].second);
            ++ctr;
        } else if (st.size() < k) {
            st.insert(v[i].second);
            ++ctr;
        }
    }

    cout << ctr << endl;

    return 0;
}
