#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
vector<int> graph[N];
bool passed[N];
vector<int> sorted;
int dist[N];
int parents[N];

void dfs(int v) {
    if (passed[v]) return;
    passed[v] = true;
    for (auto to : graph[v]) {
        dfs(to);
    }
    sorted.push_back(v);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!passed[i]) dfs(i);
    }

    reverse(sorted.begin(), sorted.end());

    int ptr = 0;
    while (sorted[ptr] != 1) ++ptr;

    for (int i = ptr; i < n && sorted[i] != n; ++i) {
        for (auto to : graph[sorted[i]]) {
            if (dist[sorted[i]] + 1 > dist[to]) {
                dist[to] = dist[sorted[i]] + 1;
                parents[to] = sorted[i];
            }
        }
    }

    if (dist[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int x = n;
        vector<int> path;
        while (x != 1) {
            path.push_back(x);
            x = parents[x];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (auto i : path) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
