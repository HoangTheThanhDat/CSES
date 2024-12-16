#include <bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 68;

int n , q , a[maxn] , x , k;
long long prefix = 0;

struct datait {
        long long mx , mn , res;

        datait() {
                mx = mn = res = 0;
        }

        friend datait operator + (const datait &x , const datait &y) {
                datait ans;

                ans.res = max({x.res , y.res , y.mx - x.mn});

                ans.mx = max(x.mx , y.mx);
                ans.mn = min(x.mn , y.mn);

                return ans;
        }
};

struct SegmentTree {
        datait tree[maxn * 4];
        long long lazy[maxn * 4];

        void downlazy(int id) {
                tree[id << 1].mx += lazy[id];
                tree[id << 1].mn += lazy[id];

                tree[id << 1 | 1].mx += lazy[id];
                tree[id << 1 | 1].mn += lazy[id];

                lazy[id << 1] += lazy[id];
                lazy[id << 1 | 1] += lazy[id];

                lazy[id] = 0;
        }

        void update(int id , int l , int r , int u , int v , long long val) {
                if (l > v || r < u) return;

                if (l >= u && r <= v) {
                        tree[id].mx += val;
                        tree[id].mn += val;

                        lazy[id] += val;

                        return;
                }

                downlazy(id);

                int mid = l + r >> 1;

                update(id << 1 , l , mid , u , v , val);
                update(id << 1 | 1 , mid + 1 , r , u , v , val);

                tree[id] = tree[id << 1] + tree[id << 1 | 1];
        }
} it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        it.update(1 , 0 , n , 0 , 0 , 0);

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];

                it.update(1 , 0 , n , i , n , a[i]);
        }

        while (q--) {
                cin >> k >> x;

                it.update(1 , 0 , n , k , n , x - a[k]);

                a[k] = x;

                cout << it.tree[1].res << '\n';
        }

        return 0;
}