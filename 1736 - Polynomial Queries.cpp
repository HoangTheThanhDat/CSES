#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , q , a[maxn] , type , l , r;

struct SegmentTree {
        long long tree[maxn * 4];

        struct datalazy {
                long long val;
                int dis;

                datalazy() {
                        val = dis = 0;
                }
        } lazy[maxn * 4];

        long long sum(int l , int cnt , int dis) {
                long long r = l + 1ll * dis * (cnt - 1);

                return 1ll * (l + r) * ((r - l) / dis + 1) / 2;
        }

        void downlazy(int id , int l , int r) {
                int mid = l + r >> 1;

                lazy[id << 1].val += lazy[id].val;
                lazy[id << 1].dis += lazy[id].dis;

                tree[id << 1] += sum(lazy[id].val , mid - l + 1 , lazy[id].dis);

                long long newval = lazy[id].val + 1ll * (mid - l + 1) * lazy[id].dis;

                lazy[id << 1 | 1].val += newval;
                lazy[id << 1 | 1].dis += lazy[id].dis;

                tree[id << 1 | 1] += sum(newval , r - mid , lazy[id].dis);

                lazy[id].val = lazy[id].dis = 0;
        }

        void build(int id , int l , int r) {
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

        void update(int id , int l , int r , int u , int v) {
                if (l > v || r < u) return;

                if (l >= u && r <= v) {
                        tree[id] += sum(l - u + 1 , r - l + 1 , 1);

                        lazy[id].val += l - u + 1;
                        ++lazy[id].dis;

                        return;
                }

                int mid = l + r >> 1;

                if (lazy[id].val > 0) downlazy(id , l , r);

                update(id << 1 , l , mid , u , v);
                update(id << 1 | 1 , mid + 1 , r , u , v);

                tree[id] = tree[id << 1] + tree[id << 1 | 1];
        }

        long long get(int id , int l , int r , int u , int v) {
                if (l > v || r < u) return 0;

                if (l >= u && r <= v) return tree[id];

                int mid = l + r >> 1;

                if (lazy[id].val > 0) downlazy(id , l , r);

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

                if (type & 1) 
                        it.update(1 , 1 , n , l , r);
                else    
                        cout << it.get(1 , 1 , n , l , r) << '\n';
        }

        return 0;
}