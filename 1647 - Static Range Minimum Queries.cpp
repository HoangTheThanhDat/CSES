#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const int inf = 1e9 + 68;

int n , a[maxn] , q , l , r;

struct SegmentTree {
        int tree[maxn * 4];

        void build(int id , int l , int r) {
                if (l > r) return;

                if (l == r) {
                        tree[id] = a[l];
                        return;
                }

                int mid = l + r >> 1;

                build(id << 1 , l , mid);
                build(id << 1 | 1 , mid + 1 , r);

                tree[id] = min(tree[id << 1] , tree[id << 1 | 1]);
        }

        int get(int id , int l , int r , int u , int v) {
                if (l > v || r < u) return inf;

                if (l >= u && r <= v) return tree[id];

                int mid = l + r >> 1;

                int left = get(id << 1 , l , mid , u , v);
                int right = get(id << 1 | 1 , mid + 1 , r , u , v);

                return min(left , right);
        }
} it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        it.build(1 , 1 , n);

        while (q--) {
                cin >> l >> r;

                cout << it.get(1 , 1 , n , l , r) << '\n';
        }  

        return 0;
}