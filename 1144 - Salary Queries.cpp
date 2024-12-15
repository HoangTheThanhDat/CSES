#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , q , a[maxn] , l[maxn] , r[maxn];
char type[maxn];

vector<int> zip;

struct SegmentTree {
        int tree[maxn * 3 * 4];

        void update(int id , int l , int r , int idx , int val) {
                if (l > idx || r < idx) return;

                if (l == r) {
                        tree[id] += val;

                        return;
                }

                int mid = l + r >> 1;

                update(id << 1 , l , mid , idx , val);
                update(id << 1 | 1 , mid + 1 , r , idx , val);

                tree[id] = tree[id << 1] + tree[id << 1 | 1];
        }

        int get(int id , int l , int r , int u , int v) {
                if (l > v || r < u) return 0;

                if (l >= u && r <= v) return tree[id];

                int mid = l + r >> 1;

                int left = get(id << 1 , l , mid , u , v);
                int right = get(id << 1 | 1 , mid + 1 , r , u , v);

                return left + right;
        }
} it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) cin >> a[i] , zip.push_back(a[i]);

        for (int i = 1 ; i <= q ; i++) {
                cin >> type[i] >> l[i] >> r[i];

                if (type[i] == '!') zip.push_back(l[i]);

                zip.push_back(r[i]);
        }

        sort(zip.begin() , zip.end());
        zip.resize(unique(zip.begin() , zip.end()) - zip.begin());

        for (int i = 1 ; i <= n ; i++) a[i] = lower_bound(zip.begin() , zip.end() , a[i]) - zip.begin() + 1;

        for (int i = 1 ; i <= q ; i++) {
                if (type[i] == '?') l[i] = lower_bound(zip.begin() , zip.end() , l[i]) - zip.begin() + 1;
                r[i] = lower_bound(zip.begin() , zip.end() , r[i]) - zip.begin() + 1;
        }

        for (int i = 1 ; i <= n ; i++) it.update(1 , 1 , n + q * 2 , a[i] , 1);

        for (int i = 1 ; i <= q ; i++) 
                if (type[i] == '!') {
                        it.update(1 , 1 , n + q * 2 , a[l[i]] , -1);

                        it.update(1 , 1 , n + q * 2 , r[i] , 1);
                        
                        a[l[i]] = r[i];
                }
                else 
                        cout << it.get(1 , 1 , n + q * 2 , l[i] , r[i]) << '\n';

        return 0;
}