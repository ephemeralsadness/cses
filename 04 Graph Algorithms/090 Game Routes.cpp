#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;
vector<int> graph[N];
bool passed[N];
vector<int> sorted;
ll amount[N];

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

    amount[1] = 1;
    for (int i = 0; i < n; ++i) {
        for (auto to : graph[sorted[i]]) {
            amount[to] = (amount[to] + amount[sorted[i]]) % MOD;
        }
    }

    cout << amount[n] << endl;

    return 0;
}
