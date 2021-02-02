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
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        q.push(x);
        int y = q.front();
        q.pop();
        cout << y << ' ';
    }
    cout << endl;

    return 0;
}
