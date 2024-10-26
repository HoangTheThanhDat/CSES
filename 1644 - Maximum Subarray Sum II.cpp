#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first 
#define se second 
#define el '\n'
#define reset(__a , __v) memset(__a,__v,sizeof(__a))
#define datmacoder int32_t main()
#define openfile(__dat) if (fopen(__dat".inp","r")){freopen(__dat".inp","r",stdin);freopen(__dat".out","w",stdout);}

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

const int N = 2e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

struct SegmentTree {
        ll tree[N * 4];

        SegmentTree() {
                for (int i = 0 ; i < N * 4 ; i++) tree[i] = oo;
        }

        void update(int id , int l , int r , int idx , ll value) {
                if (l > idx || r < idx) return;

                if (l == r) {
                        tree[id] = value;
                        return;
                }
                int mid = l + r >> 1;

                update(id << 1 , l , mid , idx , value);
                update(id << 1 | 1 , mid + 1 , r , idx , value);

                tree[id] = min(tree[id << 1] , tree[id << 1 | 1]);
        }

        ll get(int id , int l , int r , int u , int v) {
                if (l > v || r < u) return oo;

                if (l >= u && r <= v) return tree[id];

                int mid = l + r >> 1;

                ll left = get(id << 1 , l , mid , u , v);
                ll right = get(id << 1 | 1 , mid + 1 , r , u , v);

                return min(left , right);
        }
} it;

int n , so , a , b;
ll ans = -oo , s = 0 , _get;

void solve() {
        cin >> n >> a >> b;

        it.update(1 , 0 , n , 0 , 0);

        for (int i = 1 ; i <= n ; i++) {
                cin >> so;

                s += so;

                it.update(1 , 0 , n , i , s);

                if (i >= a) {
                        _get = it.get(1 , 0 , n , max(0 , i - b) , i - a);

                        if (ans == -oo) 
                                ans = s - _get;
                        else    
                                maximize(ans , 1ll * s - _get);
                }
        }

        cout << ans << el;
}

datmacoder {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        openfile("txt");

        int testcase;
        if (!TESTCASE) testcase = 1;
        else cin >> testcase;

        while (testcase--) {
                solve();
        }

        return 0;
}

/* 
        d a t m a . _ c o d e r
        H O A N G   T H E   T H A N H   D A T
*/