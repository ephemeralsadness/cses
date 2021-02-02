#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
vector<int> g[N];
char passed[N];
vector<int> sorted;

bool dfs(int v) {
    if (passed[v] == 1) return true;
    if (passed[v] == 2) return false;
    passed[v] = 1;
    for (auto to : g[v]) {
        if (dfs(to)) return true;
    }
    passed[v] = 2;
    sorted.push_back(v);
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
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (dfs(i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    reverse(sorted.begin(), sorted.end());
    for (auto i : sorted) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
