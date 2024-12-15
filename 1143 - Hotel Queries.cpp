#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , m , a[maxn] , b;

struct SegmentTree {
        int tree[maxn * 4];

        void update(int id , int l , int r , int idx , int val) {
                if (l > idx || r < idx) return;

                if (l == r) {
                        tree[id] += val;
                        return;
                }

                int mid = l + r >> 1;

                update(id << 1 , l , mid , idx , val);
                update(id << 1 | 1 , mid + 1 , r , idx , val);
                
                tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
        }

        int get(int id , int l , int r , int val) {
                if (l == r) 
                        if (tree[id] >= val)    
                                return l;
                        else 
                                return 0;

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

        cin >> n >> m;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];
                
                it.update(1 , 1 , n , i , a[i]);
        }   

        for (int i = 1 ; i <= m ; i++) {
                cin >> b;

                int res = it.get(1 , 1 , n , b);

                if (res != 0) it.update(1 , 1 , n , res , -b);

                cout << res << ' ';
        }

        return 0;
}