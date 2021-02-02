#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000;

vector<int> g[N + 1];
int from[N + 1];


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("test_input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<pii> q;
    q.emplace(1, -1);
    while (!q.empty()) {
        auto [v, f] = q.front();
        q.pop();

        if (from[v] != 0)
            continue;
        from[v] = f;

        for (auto to : g[v]) {
            q.emplace(to, v);
        }
    }

    vector<int> v;
    if (from[n] != 0) {
        while (from[n] != -1) {
            v.push_back(n);
            n = from[n];
        }
        v.push_back(1);
        reverse(v.begin(), v.end());

        cout << v.size() << endl;
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
