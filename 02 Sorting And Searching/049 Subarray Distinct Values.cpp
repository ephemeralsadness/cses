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
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    map<int, int> mp;

    ll sm = 0;
    int right = n;
    for (int left = n - 1; left >= 0; --left) {
        ++mp[v[left]];
        while ((int)mp.size() > k) {
            --right;
            auto it = mp.find(v[right]);
            --(it->second);
            if (it->second == 0)
                mp.erase(it);
        }
        sm += (right - left);
    }

    cout << sm << endl;

    return 0;
}
