#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1LL << 60;
struct edge {
    int a, b;
    ll c;
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }
    vector<ll> routes(n + 1, 0);
    vector<int> parents(n + 1);

    int x = -1;
    for (int i = 0; i < n; ++i) {
        for (edge e : edges) {
            if (routes[e.a] != INF) {
                if (routes[e.a] + e.c < routes[e.b]) {
                    routes[e.b] = routes[e.a] + e.c;
                    parents[e.b] = e.a;
                    if (i == n - 1) {
                        x = e.a;
                        break;
                    }
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        unordered_set<int> what;
        while (!what.count(x)) {
            what.insert(x);
            x = parents[x];
        }

        vector<int> cycle;
        int y = parents[x];
        cycle.push_back(x);
        while (y != x) {
            cycle.push_back(y);
            y = parents[y];
        }
        cycle.push_back(x);

        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for (auto i : cycle) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
