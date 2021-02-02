#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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


    tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> t;

    int n; cin >> n;
    vector<pair<pii, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), [](pair<pii, int>& lhs, pair<pii, int>& rhs) {
        if (lhs.first.first == rhs.first.first) return rhs.first.second < lhs.first.second;
        return lhs.first.first < rhs.first.first;
    });

    vector<int> from(n);
    vector<int> to(n);

    tree<pii, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> tree_one;
    tree_one.insert({v[0].first.second, v[0].second});
    for (int i = 1; i < n; ++i) {
        to[v[i].second] = tree_one.order_of_key(pii{v[i].first.second - 1, n});
        tree_one.insert({v[i].first.second, i});
    }

    tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> tree_two;
    tree_two.insert({v[n - 1].first.second, v[n - 1].second});
    for (int i = n - 2; i >= 0; --i){
        from[v[i].second] = tree_two.order_of_key(pii{v[i].first.second + 1, 0});
        tree_two.insert({v[i].first.second, i});
    }

    for (int i = 0; i < n; ++i) {
        cout << from[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << to[i] << ' ';
    }
    cout << endl;

    return 0;
}
