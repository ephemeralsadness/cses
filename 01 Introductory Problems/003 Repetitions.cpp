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

    string dna; cin >> dna;
    int n = dna.size();

    int mx = 1;
    int now = 1;

    for (int i = 1; i < n; ++i) {
        if (dna[i - 1] == dna[i]) {
            ++now;
        } else {
            now = 1;
        }
        mx = max(mx, now);
    }

    cout << mx << endl;

    return 0;
}
