#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const long long inf = 1e18;

int n , q , a[maxn] , type , l , r;

struct SegmentTree {
        long long tree[maxn * 4];
        long long lazy[maxn * 4];

        void downlazy(int id) {
                tree[id << 1] += lazy[id];
                lazy[id << 1] += lazy[id];

                tree[id << 1 | 1] += lazy[id];
                lazy[id << 1 | 1] += lazy[id];
                
                lazy[id] = 0;
        }

        void update(int id , int l , int r , int u , int v , int val) {
                if (l > v || r < u) return;

                if (l >= u && r <= v) {
                        tree[id] += val;
                        lazy[id] += val;

                        return;
                }

                downlazy(id);

                int mid = l + r >> 1;

                update(id << 1 , l , mid , u , v , val);
                update(id << 1 | 1 , mid + 1 , r , u , v , val);

                tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
        }
        
        long long get(int id , int l , int r , int u , int v) {
                if (u == 0 && v == 0) return 0;
                
                if (l > v || r < u) return -inf;

                if (l >= u && r <= v) return tree[id];

                downlazy(id);

                int mid = l + r >> 1;

                long long left = get(id << 1 , l , mid , u , v);
                long long right = get(id << 1 | 1 , mid + 1 , r , u , v);

                return max(left , right);
        }
} it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];

                it.update(1 , 1 , n , i , n , a[i]);
        }

        while (q--) {
                cin >> type >> l >> r;

                if (type & 1) {
                        it.update(1 , 1 , n , l , n , r - a[l]);

                        a[l] = r;
                }
                else 
                        cout << max(0ll , it.get(1 , 1 , n , l , r) - it.get(1 , 1 , n , l - 1 , l - 1)) << '\n';
        }

        return 0;
}