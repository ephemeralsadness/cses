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
    vector<pii> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](pii lhs, pii rhs) -> bool {
        return lhs.second < rhs.second;
    });

    int free_time = 0;
    int ctr = 0;
    for (int i = 0; i < n; ++i) {
        if (movies[i].first >= free_time) {
            ++ctr;
            free_time = movies[i].second;
        }
    }

    cout << ctr << endl;

    return 0;
}
