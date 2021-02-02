#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
vector<pii> graph[N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    const ll INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
    vector<ll> shortest_ways(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [ln, vertex] = pq.top();
        pq.pop();
        if (shortest_ways[vertex] != INF) continue;

        shortest_ways[vertex] = ln;
        for (auto [c, b] : graph[vertex]) {
            pq.emplace(ln + c, b);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << shortest_ways[i] << ' ';
    }
    cout << endl;

    return 0;
}
