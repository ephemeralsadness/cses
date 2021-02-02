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

    string s; cin >> s;
    int n = s.size();
    int m = 'Z' - 'A' + 1;
    vector<int> v(m);

    for (int i = 0; i < n; ++i) {
        ++v[s[i] - 'A'];
    }

    int even = 0;
    int odd = 0;
    for (int i = 0; i < m; ++i) {
        if (v[i] % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION" << endl;
    } else {
        string p(n, ' ');
        int ptr = 0;

        for (int i = 0; i < m; ++i) {
            if (v[i] % 2 == 1) {
                p[n / 2] = 'A' + i;
                --v[i];
            }
            while (v[i]) {
                p[ptr] = p[n - 1 - ptr] = 'A' + i;
                ++ptr;
                v[i] -= 2;
            }
        }

        cout << p << endl;

    }


    return 0;
}
