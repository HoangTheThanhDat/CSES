#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , q , so , l , r;

struct BIT {
        long long bit[maxn];

        void update(int idx , int val) {
                for (; idx <= n ; idx += idx & -idx) bit[idx] += val;
        }

        long long get(int idx) {
                long long res = 0;

                for (; idx > 0 ; idx &= idx - 1) res += bit[idx];

                return res;
        }
} fenwick;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) {
                cin >> so;

                fenwick.update(i , so);
        }

        while (q--) {
                cin >> l >> r;

                cout << fenwick.get(r) - fenwick.get(l - 1) << '\n';
        }

        return 0;
}