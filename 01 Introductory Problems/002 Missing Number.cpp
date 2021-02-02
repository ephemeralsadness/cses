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
    vector<char> v(n + 1, false);
    for (int i = 1; i < n; ++i) {
        int x; cin >> x;
        v[x] = true;
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) {
            answer = i;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}
