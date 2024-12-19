#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , q , a[maxn] , type , l , r , val;

struct SegmentTree {
        long long tree[maxn * 4];
        long long lazy[maxn * 4];
        bool ass[maxn * 4];

        SegmentTree() {
                memset(ass , false , sizeof ass);
                memset(lazy , 0 , sizeof lazy);
        }

        void build(int id , int l  , int r) {
                if (l > r) return;

                if (l == r) {
                        tree[id] = a[l];
                        return;
                }

                int mid = l + r >> 1;

                build(id << 1 , l , mid);
                build(id << 1 | 1 , mid + 1 , r);

                tree[id] = tree[id << 1] + tree[id << 1 | 1];
        }

        void downlazy(int id , int l , int r) {
                int mid = l + r >> 1;

                if (ass[id] == true) {
                        tree[id << 1] = 1ll * (mid - l + 1) * lazy[id];
                        lazy[id << 1] = lazy[id];

                        tree[id << 1 | 1] = 1ll * (r - mid) * lazy[id];
                        lazy[id << 1 | 1] = lazy[id];

                        ass[id << 1] = ass[id << 1 | 1] = true;
                        ass[id] = false;
                }
                else {
                        tree[id << 1] += 1ll * (mid - l + 1) * lazy[id];
                        lazy[id << 1] += lazy[id];

                        tree[id << 1 | 1] += 1ll * (r - mid) * lazy[id];
                        lazy[id << 1 | 1] += lazy[id];
                }

                lazy[id] = 0;
        }

        void update_assign(int id , int l , int r , int u , int v , int val) {
                if (l > v || r < u) return;

                if (l >= u && r <= v) {
                        tree[id] = 1ll * (r - l + 1) * val;
                        lazy[id] = val;
                        ass[id] = true;

                        return;
                }

                downlazy(id , l , r);

                int mid = l + r >> 1;

                update_assign(id << 1 , l , mid , u , v , val);
                update_assign(id << 1 | 1 , mid + 1 , r , u , v , val);

                tree[id] = tree[id << 1] + tree[id << 1 | 1];
        }

        void update_inc(int id , int l , int r , int u , int v , int val) {
                if (l > v || r < u) return;

                if (l >= u && r <= v) {
                        tree[id] += 1ll * (r - l + 1) * val;
                        lazy[id] += val;
                        
                        return;
                }

                downlazy(id , l , r);

                int mid = l + r >> 1;

                update_inc(id << 1 , l , mid , u , v , val);
                update_inc(id << 1 | 1 , mid + 1 , r , u , v , val);

                tree[id] = tree[id << 1] + tree[id << 1 | 1];
        }

        long long get(int id , int l , int r , int u , int v) {
                if (l > v || r < u) return 0ll;

                if (l >= u && r <= v) return tree[id];

                downlazy(id , l , r);

                int mid = l + r >> 1;

                long long left = get(id << 1 , l , mid , u , v);
                long long right = get(id << 1 | 1 , mid + 1 , r , u , v);

                return left + right;
        }
} it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        it.build(1 , 1 , n);

        while (q--) {
                cin >> type >> l >> r;

                if (type == 1) {
                        cin >> val;

                        it.update_inc(1 , 1 , n , l , r , val);
                }
                else if (type == 2) {
                        cin >> val;

                        it.update_assign(1 , 1 , n , l , r , val);
                }
                else 
                        cout << it.get(1 , 1 , n , l , r) << '\n';
        }

        return 0;
}