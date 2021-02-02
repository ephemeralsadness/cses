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
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll left = *max_element(v.begin(), v.end());
    ll right = accumulate(v.begin(), v.end(), 0LL) + 1;

    ll mn = right;
    while (left < right) {
        ll mid = (left + right) / 2;

        int subarray = 1;
        ll sm = 0;
        for (int i = 0; i < n; ++i) {
            if (sm + v[i] <= mid) {
                sm += v[i];
            } else {
                ++subarray;
                sm = v[i];
            }
        }

        if (subarray <= k) {
            mn = min(mn, mid);
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << mn << endl;

    return 0;
}
