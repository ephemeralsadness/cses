#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 7;
const int S = 48;
bool passed[N][N];
string pattern;
string result;


int rec(int x, int y, int s) {
    if (x == 6 && y == 0)
        return s == S;

    if (passed[x][y])
        return 0;


    if ((y == 0 || y == 6) && ((x > 0 && !passed[x - 1][y]) || (x < 6 && passed[x + 1][y])))
        return 0;
    if (x == 0 && ((y > 0 && !passed[x][y - 1]) || (y < 6 && passed[x][y + 1])))
        return 0;
    if (x == 6 && ((y < 6 && !passed[x][y + 1]) || (y > 0 && passed[x][y - 1])))
        return 0;
    if (x > 0 && y == 5 && passed[x - 1][y] && !passed[x - 1][y + 1])
        return 0;
    if (x == 1 && y > 0 && passed[x][y - 1] && !passed[x - 1][y - 1])
        return 0;
    if (x > 0 && y == 1 && passed[x - 1][y] && !passed[x - 1][y - 1])
        return 0;
    if (x > 0 && x < 6 && y > 0 && y < 6) {
        if (passed[x - 1][y] && passed[x + 1][y] && !passed[x][y + 1] && !passed[x][y - 1])
            return 0;
        if (passed[x][y - 1] && passed[x][y + 1] && !passed[x - 1][y] && !passed[x + 1][y])
            return 0;
    }

    int sm = 0;
    passed[x][y] = true;

    if (x > 0 && (pattern[s] == '?' || pattern[s] == 'U')) {
        result[s] = 'U';
        sm += rec(x - 1, y, s + 1);
    }
    if (x < 6 && (pattern[s] == '?' || pattern[s] == 'D')) {
        result[s] = 'D';
        sm += rec(x + 1, y, s + 1);
    }
    if (y > 0 && (pattern[s] == '?' || pattern[s] == 'L')) {
        result[s] = 'L';
        sm += rec(x, y - 1, s + 1);
    }
    if (y < 6 && (pattern[s] == '?' || pattern[s] == 'R')) {
        result[s] = 'R';
        sm += rec(x, y + 1, s + 1);
    }

    passed[x][y] = false;
    return sm;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> pattern;
    result.resize(S, ' ');
    cout << rec(0, 0, 0) << endl;


    return 0;
}
