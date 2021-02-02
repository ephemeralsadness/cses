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

    vector<int> tmp(k);
    for (int i = 0; i < k; ++i) {
        tmp[i] = v[i];
    }
    sort(tmp.begin(), tmp.end());
    int mid = (k - 1) / 2;

    multiset<int> left_set;
    multiset<int> right_set;

    int median = tmp[mid];
    for (int i = 0; i < mid; ++i)
        left_set.insert(tmp[i]);
    for (int i = mid + 1; i < k; ++i)
        right_set.insert(tmp[i]);

    // condition l.size - r.size == -1 | 0

    for (int i = k; i < n; ++i) {
        cout << median << ' ';
        if (v[i] < median)
            left_set.insert(v[i]);
        else
            right_set.insert(v[i]);

        if (left_set.find(v[i - k]) != left_set.end())
            left_set.erase(left_set.find(v[i - k]));
        else if (right_set.find(v[i - k]) != right_set.end())
            right_set.erase(right_set.find(v[i - k]));
        else {
            if (!left_set.empty()) {
                median = *prev(left_set.end());
                left_set.erase(prev(left_set.end()));
            } else {
                median = *right_set.begin();
                right_set.erase(right_set.begin());
            }
        }

        while (left_set.size() > right_set.size()) {
            right_set.insert(median);
            median = *prev(left_set.end());
            left_set.erase(prev(left_set.end()));
        }

        while (right_set.size() > left_set.size() + 1) {
            left_set.insert(median);
            median = *right_set.begin();
            right_set.erase(right_set.begin());
        }
    }

    cout << median << endl;

    return 0;
}
