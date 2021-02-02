#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1LL << 60;
struct edge {
    int a, b;
    ll x;
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
        cin >> edges[i].a >> edges[i].b >> edges[i].x;
        edges[i].x = -edges[i].x;
    }

    vector<ll> routes(n + 1, INF);
    routes[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        bool any = false;
        for (auto& e : edges) {
            if (routes[e.a] != INF) {
                if (routes[e.b] > routes[e.a] + e.x) {
                    routes[e.b] = routes[e.a] + e.x;
                    any = true;
                }
            }
        }
        if (!any) break;
    }

    vector<char> passed(n + 1, false);
    for (auto& e : edges) {
        if (routes[e.a] != INF) {
            if (routes[e.b] > routes[e.a] + e.x) {
                routes[e.b] = routes[e.a] + e.x;
                passed[e.b] = true;
            }
        }
    }

    queue<int> bfs;
    for (int i = 1; i <= n; ++i) {
        if (passed[i]) {
            bfs.emplace(i);
            passed[i] = false;
        }
    }

    if (bfs.empty()) {
        cout << -routes[n] << endl;
    } else {
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            g[e.a].push_back(e.b);
        }

        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();

            if (passed[v]) continue;
            passed[v] = true;

            for (auto to : g[v]) {
                bfs.push(to);
            }
        }

        if (passed[n]) {
            cout << -1 << endl;
        } else {
            cout << -routes[n] << endl;
        }
    }

    return 0;
}
