#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
const ll INF = 1LL << 60;
const ll MOD = 1000 * 1000 * 1000 + 7;
vector<pii> graph[N];
ll distances[N];
ll amount[N];
ll mn_edges[N];
ll mx_edges[N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    for (int i = 1; i <= n; ++i) {
        distances[i] = INF;
        mn_edges[i] = INF;
        mx_edges[i] = -INF;
    }

    distances[0] = 0;
    amount[0] = 1;
    mn_edges[0] = mx_edges[0] = -1;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    pq.emplace(0, 1, 0);
    while (!pq.empty()) {
        auto [dist, ver, par] = pq.top();
        pq.pop();
        if (distances[ver] < dist) continue;
        bool alpha = (distances[ver] != dist);
        distances[ver] = dist;
        amount[ver] = (amount[ver] + amount[par]) % MOD;
        mn_edges[ver] = min(mn_edges[ver], mn_edges[par] + 1);
        mx_edges[ver] = max(mx_edges[ver], mx_edges[par] + 1);

        if (alpha) {
            for (auto [to, d] : graph[ver]) {
                pq.emplace(distances[ver] + d, to, ver);
            }
        }
    }

    cout << distances[n] << ' ' << amount[n] << ' ' << mn_edges[n] << ' ' << mx_edges[n] << endl;

    return 0;
}
