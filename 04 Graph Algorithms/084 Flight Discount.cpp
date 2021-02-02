#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
const ll INF = 1LL << 60;
vector<pii> graph[N];
ll routes[N][2];

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
        routes[i][0] = routes[i][1] = INF;
    }

    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<>> pq;
    pq.emplace(0, 1, false);

    while (!pq.empty()) {
        auto [d, v, coupon] = pq.top();
        pq.pop();

        if (routes[v][coupon] != INF) continue;
        routes[v][coupon] = d;

        for (auto [to, to_d] : graph[v]) {
            pq.emplace(d + to_d, to, coupon);
        }

        if (!coupon) {
            for (auto [to, to_d] : graph[v]) {
                pq.emplace(d + to_d / 2, to, true);
            }
        }
    }

    cout << min(routes[n][0], routes[n][1]) << endl;

    return 0;
}
