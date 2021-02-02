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
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> a;
        vector<int> b;

        int s = 1;
        if (n % 4 == 3) {
            a.push_back(1); a.push_back(2);
            b.push_back(3);
            s = 4;
        }

        while (s < n) {
            a.push_back(s); a.push_back(s + 3);
            b.push_back(s + 1); b.push_back(s + 2);
            s += 4;
        }

        cout << a.size() << endl;
        for (int x : a) {
            cout << x << ' ';
        }
        cout << endl;

        cout << b.size() << endl;
        for (int x : b) {
            cout << x << ' ';
        }
        cout << endl;

    }


    return 0;
}
