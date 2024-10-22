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

int n;
ll t , a[N];

ll count(ll time , int limit) {
        ll res = 0;

        for (int i = 1 ; i <= n ; i++) {
                res += time / a[i];
                if (res > limit) return res;
        }

        return res;
}

ll BinarySearch(ll l , ll r , ll x) {
        ll mid , res = 0;

        while (l <= r) {
                mid = l + r >> 1;

                if (count(mid , x) >= x)
                        res = mid , 
                        r = mid - 1;
                else
                        l = mid + 1;
        }

        return res;
}

void solve() {
        cin >> n >> t;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        cout << BinarySearch(0 , 1e18 , t) << el;
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
