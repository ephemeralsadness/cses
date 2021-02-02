#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2 * 1e5;
int fenwick[N];
int n, k;

int sum(int r) {
    int result = 0;
    while (r >= 0) {
        result += fenwick[r];
        r = (r & (r + 1)) - 1;
    }
    return result;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void inc(int i, int d) {
    while (i < n) {
        fenwick[i] += d;
        i = i | (i + 1);
    }
}

int bin_search(int now, int to_skip) {
    int from_right = sum(min(now + 1, n - 1), n - 1);

    int mn = n;
    int mid = 0;
    if (from_right <= to_skip) {
        to_skip -= (from_right - 1);
        // бинарный поиск для диапазона [0, now], l = 0, r - значение
        int l = 0;
        int r = now;
        while (l < r) {
            mid = (l + r) / 2;
            if (sum(0, mid) >= to_skip) {
                r = mid;
                mn = min(mn, mid);
            } else {
                l = mid + 1;
            }
        }
    } else {
        to_skip++;
        // бинарный поиск для диапазона [now, n - 1], l = now + 1, r - значение
        int l = now;
        int r = n;
        while (l < r) {
            mid = (l + r) / 2;
            if (sum(now + 1, mid) >= to_skip) {
                r = mid;
                mn = min(mn, mid);
            } else {
                l = mid + 1;
            }
        }
    }

    inc(mn, -1);

    return mn;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(20);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        inc(i, 1);
    }

    int ptr = (k % n);
    inc(ptr, -1);
    cout << ptr + 1 << ' ';
    for (int i = n - 1; i > 0; --i) {
        int to_skip = (k % i);
        ptr = bin_search(ptr, to_skip);
        cout << ptr + 1 << ' ';
    }
    cout << endl;


    return 0;
}
