#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
const ll INF = 1LL << 60;
vector<int> graph[N];
char passed[N];
int parents[N];
int cycle_start = -1;
int cycle_end = -1;

bool dfs(int v, int prev) {
    if (passed[v] == 0) {
        passed[v] = 1;
        parents[v] = prev;
        for (auto to : graph[v]) {
            if (dfs(to, v)) return true;
        }
    } else if (passed[v] == 1) {
        cycle_start = prev;
        cycle_end = v;
        return true;
    }
    passed[v] = 2;
    return false;
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
        if (passed[i]) continue;
        if (dfs(i, 0)) {
            vector<int> path;
            path.push_back(cycle_end);
            while (cycle_start != cycle_end) {
                path.push_back(cycle_start);
                cycle_start = parents[cycle_start];
            }
            path.push_back(cycle_end);
            reverse(path.begin(), path.end());

            cout << path.size() << endl;
            for (auto j : path) {
                cout << j << ' ';
            }
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
