#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
const ll INF = 1LL << 60;
vector<pii> graph[N];
vector<ll> distances[N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    for (int i = 1; i <= n; ++i) {
        distances[i].assign(k, INF);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (distances[v][k - 1] < d) continue;
        distances[v][k - 1] = d;
        sort(distances[v].begin(), distances[v].end());

        for (auto [c, to] : graph[v]) {
            pq.emplace(d + c, to);
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << distances[n][i] << ' ';
    }
    cout << endl;

    return 0;
}
