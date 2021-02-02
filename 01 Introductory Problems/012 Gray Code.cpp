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
    int p2n = 1 << n;


    for (int i = 0; i < p2n; ++i) {
        int g = i ^ (i >> 1);

        string bin(n, '0');
        int ptr = n - 1;
        while (g) {
            if (g & 1) bin[ptr] = '1';
            g >>= 1;
            --ptr;
        }

        cout << bin << '\n';
    }

    return 0;
}
