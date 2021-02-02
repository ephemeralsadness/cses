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

    set<int> st;
    int left = 0;
    int mx = 0;
    for (int right = 0; right < n; ++right) {
        if (st.count(v[right])) {
            while (v[left] != v[right]) {
                st.erase(v[left]);
                ++left;
            }
            st.erase(v[left]);
            ++left;
        }
        st.insert(v[right]);
        mx = max(mx, right - left + 1);
    }

    cout << mx << endl;

    return 0;
}
