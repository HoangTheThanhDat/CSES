#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , q , a[maxn] , type , k , u , v , curver = 0;
vector<int> ver;

struct dataver {
        int left;
        int right;
        long long sum;
} tree[maxn * 40];

struct PerSegmentTree {
        void build(int &root , int l , int r) {
                ++curver;

                root = curver;

                if (l == r) {
                        tree[root].sum = a[l];
                        return;
                }

                int mid = l + r >> 1;

                build(tree[root].left , l , mid);
                build(tree[root].right , mid + 1 , r);

                tree[root].sum = tree[tree[root].left].sum + tree[tree[root].right].sum;
        }

        void update(int &root , int l , int r , int idx , long long val) {
                ++curver;

                tree[curver].left = tree[root].left;
                tree[curver].right = tree[root].right;
                tree[curver].sum = tree[root].sum + val;

                root = curver;

                if (l == r) return;

                int mid = l + r >> 1;

                if (idx <= mid) update(tree[root].left , l , mid , idx , val);
                else update(tree[root].right , mid + 1 , r , idx , val);
        }

        long long get(int VER , int l , int r , int u , int v) {
                if (l > v || r < u) return 0;

                if (l >= u && r <= v) return tree[VER].sum;

                int mid = l + r >> 1;

                long long left = get(tree[VER].left , l , mid , u , v);
                long long right = get(tree[VER].right , mid + 1 , r , u , v);

                return left + right;

        }
} it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        ver.push_back(0);

        it.build(ver[0] , 1 , n);

        while (q--) {
                cin >> type;

                if (type == 3) {
                        cin >> k;
                        ver.push_back(ver[k - 1]);
                }
                else if (type == 2) {
                        cin >> k >> u >> v;
                        cout << it.get(ver[k - 1] , 1 , n , u , v) << '\n';
                }
                else if (type == 1) {
                        cin >> k >> u >> v;
                        it.update(ver[k - 1] , 1 , n , u , v - it.get(ver[k - 1] , 1 , n , u , u));
                }
        }

        return 0;
}