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
    ll x; cin >> x;
    vector<ll> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll left = 0;
    ll right = 0;
    ll sm = v[0];
    int ctr = 0;
    while (right < n) {
        if (sm == x) ++ctr;
        if (sm < x) {
            ++right;
            if (right != n) {
                sm += v[right];
            }
        } else {
            sm -= v[left];
            ++left;
        }
    }

    cout << ctr << endl;

    return 0;
}
