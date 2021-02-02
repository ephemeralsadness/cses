#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 500;
const ll INF = 1000000LL * 1000000 * 1000000;
ll graph[N][N];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = INF;
        }
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a - 1][b - 1] = min(graph[a - 1][b - 1], (ll)c);
        graph[b - 1][a - 1] = min(graph[b - 1][a - 1], (ll)c);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        if (graph[a - 1][b - 1] == INF) {
            cout << -1 << '\n';
        } else {
            cout << graph[a - 1][b - 1] << '\n';
        }
    }

    return 0;
}
