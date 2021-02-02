#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_DIGITS = 18;
ll digits_amount[MAX_DIGITS + 1];
ll number_dp[MAX_DIGITS + 1];

ll rec(string& s, int i) {
    if (i > 1 && s[i - 2] == s[i - 1]) return 0;
    if (i >= (int)s.size()) return 0;
    ll sm = 0;
    for (int j = '0'; j < s[i]; ++j) {
        if (s[i - 1] != j) {
            sm += digits_amount[(int)s.size() - 1 - i];
        }
    }
    sm += rec(s, i + 1);
    return sm;
}

ll solve(ll a) {
    if (a < 10)
        return a;
    string s = to_string(a);
    ll sm = number_dp[(int)s.size() - 1];
    for (int i = '1'; i < s[0]; ++i) {
        sm += digits_amount[(int)s.size() - 1];
    }
    sm += rec(s, 1);
    return sm;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    digits_amount[0] = 1;
    digits_amount[1] = 9;
    for (int i = 2; i <= MAX_DIGITS; ++i) {
        digits_amount[i] = digits_amount[i - 1] * 9;
    }

    number_dp[0] = 0;
    number_dp[1] = 10;
    for (int i = 2; i <= MAX_DIGITS; ++i) {
        number_dp[i] = number_dp[i - 1] + digits_amount[i];
    }

    ll a, b;
    cin >> a >> b;
    cout << solve(b + 1) - solve(a) << endl;

    return 0;
}
