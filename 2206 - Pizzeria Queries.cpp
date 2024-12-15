#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const int inf = 1e9 + 2e5 + 68;

int n , q , so , a[maxn] , b[maxn] , type , k , u;

struct SegmentTree {
        int tree[maxn * 4];

        void update(int id , int l , int r , int idx , int val) {
                if (l > idx || r < idx) return;

                if (l == r) {
                        tree[id] = val;
                        return;
                }

                int mid = l + r >> 1;

                update(id << 1 , l , mid , idx , val);
                update(id << 1 | 1 , mid + 1 , r , idx , val);

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
} ita , itb;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        
        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) {
                cin >> so;

                a[i] = so - i;
                b[i] = so + i;

                ita.update(1 , 1 , n , i , a[i]);
                itb.update(1 , 1 , n , i , b[i]);
        }

        while (q--) {
                cin >> type >> k;

                if (type & 1) {
                        cin >> u;
                        
                        ita.update(1 , 1 , n , k , u - k);
                        itb.update(1 , 1 , n , k , u + k);
                }
                else 
                        cout << min(ita.get(1 , 1 , n , 1 , k) + k , itb.get(1 , 1 , n , k , n) - k) << '\n';
        }

        return 0;
}