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

int n , k;
ll a[N] , sum = 0 , Max = 0;

bool check(ll limit) {
        ll cur = 0 , c = 1;

        for (int i = 1 ; i <= n ; i++) {
                cur += a[i];
                if (cur > limit) {
                        cur = a[i];
                        ++c;
                }
        }

        return c <= k;
}

ll BinarySearch(ll i , ll j) {
        ll mid , l = i , r = j , ans;

        while (l <= r) {
                mid = l + r >> 1;

                if (check(mid) == true) {
                        ans = mid;

                        r = mid - 1;
                }
                else 
                        l = mid + 1;
        }

        return ans;
}

void solve() {
        cin >> n >> k;

        for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i] , maximize(Max , a[i]);

        cout << BinarySearch(Max , sum) << el;

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
