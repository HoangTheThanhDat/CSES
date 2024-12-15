#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , a[maxn] , val;

struct SegmentTree {
        int tree[maxn * 4];
        int lazy[maxn * 4];

        void build(int id , int l , int r) {
                if (l > r) return;

                if (l == r) {
                        tree[id] = l;
                        return;
                }

                int mid = l + r >> 1;

                build(id << 1 , l , mid);
                build(id << 1 | 1 , mid + 1 , r);

                tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
        }

        void downlazy(int id) {
                tree[id << 1] -= lazy[id];
                lazy[id << 1] += lazy[id];

                tree[id << 1 | 1] -= lazy[id];
                lazy[id << 1 | 1] += lazy[id];

                lazy[id] = 0;
        }

        void update(int id , int l , int r , int u , int v) {
                if (l > v || r < u) return;

                if (l >= u && r <= v) {
                        --tree[id];
                        ++lazy[id];

                        return;
                }

                downlazy(id);

                int mid = l + r >> 1;

                update(id << 1 , l , mid , u , v);
                update(id << 1 | 1 , mid + 1 , r , u , v);

                tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
        }

        int get(int id , int l , int r , int val) {
                if (l == r) return l;

                downlazy(id);

                int mid = l + r >> 1;

                if (tree[id << 1] >= val) 
                        return get(id << 1 , l , mid , val);
                else 
                        return get(id << 1 | 1 , mid + 1 , r , val);
        }
} it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        it.build(1 , 1 , n);

        for (int i = 1 ; i <= n ; i++) {
                cin >> val;

                int res = it.get(1 , 1 , n , val);

                cout << a[res] << ' ';

                it.update(1 , 1 , n , res , n);
        }

        return 0;
}