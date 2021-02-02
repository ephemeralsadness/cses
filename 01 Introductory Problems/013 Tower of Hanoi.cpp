#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void hanoi(int from, int to, int amount) {
    if (amount == 0) return;

    hanoi(from, from ^ to, amount - 1);
    cout << from << ' ' << to << '\n';
    hanoi(from ^ to, to, amount - 1);
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; cin >> n;
    cout << (1 << n) - 1 << '\n';

    hanoi(1, 3, n);

    return 0;
}
