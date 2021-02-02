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

    ll median;
    ll left_sum_to_reach;
    ll right_sum_to_reach;
    multiset<ll> left_set;
    multiset<ll> right_set;
    {
        vector<ll> tmp(v.begin(), v.begin() + k);
        sort(tmp.begin(), tmp.end());
        int m = (k - 1) / 2;
        median = tmp[m];

        left_sum_to_reach = median * m;
        for (int i = 0; i < m; ++i) {
            left_set.insert(tmp[i]);
            left_sum_to_reach -= tmp[i];
        }

        right_sum_to_reach = -median * (k - m - 1);
        for (int i = m + 1; i < k; ++i) {
            right_set.insert(tmp[i]);
            right_sum_to_reach += tmp[i];
        }
    }

    cout << left_sum_to_reach + right_sum_to_reach << ' ';

    for (int i = k; i < n; ++i) {
        ll to_add = v[i];
        ll to_remove = v[i - k];

        if (to_add < median) {
            left_sum_to_reach += (median - to_add);
            left_set.insert(to_add);
        } else {
            right_sum_to_reach += (to_add - median);
            right_set.insert(to_add);
        }

        if (to_remove < median) {
            left_sum_to_reach -= (median - to_remove);
            left_set.erase(left_set.find(to_remove));
        } else if (to_remove > median) {
            right_sum_to_reach -= (to_remove - median);
            right_set.erase(right_set.find(to_remove));
        } else {
            if (!right_set.empty()) {
                auto nearest_from_right = right_set.begin();
                left_sum_to_reach += (ll)left_set.size() * (*nearest_from_right - median);
                right_sum_to_reach -= (ll)right_set.size() * (*nearest_from_right - median);
                median = *nearest_from_right;
                right_set.erase(nearest_from_right);
            } else {
                auto nearest_from_left = prev(left_set.end());
                left_sum_to_reach -= (ll)left_set.size() * (median - *nearest_from_left);
                right_sum_to_reach += (ll)right_set.size() * (median - *nearest_from_left);
                median = *nearest_from_left;
                left_set.erase(nearest_from_left);
            }
        }

        while (left_set.size() > right_set.size()) {
            auto nearest_from_left = prev(left_set.end());
            right_set.insert(median);
            left_sum_to_reach -= (ll)left_set.size() * (median - *nearest_from_left);
            right_sum_to_reach += (ll)(right_set.size()) * (median - *nearest_from_left);
            median = *nearest_from_left;
            left_set.erase(nearest_from_left);
        }

        while (right_set.size() > left_set.size() + 1) {
            auto nearest_from_right = right_set.begin();
            left_set.insert(median);
            left_sum_to_reach += (ll)left_set.size() * (*nearest_from_right - median);
            right_sum_to_reach -= (ll)right_set.size() * (*nearest_from_right - median);
            median = *nearest_from_right;
            right_set.erase(nearest_from_right);
        }

        cout << left_sum_to_reach + right_sum_to_reach << ' ';
    }

    cout << endl;


    return 0;
}
