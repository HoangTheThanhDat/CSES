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

const int N = 2 * 1e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2 * 1e9 + 1e8 + 6688;
const ll oo = 3 * 1e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , k;
int a[N] , b[N];

void solve() {
        cin >> n >> m >> k;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        for (int i = 1 ; i <= m ; i++) cin >> b[i];

        sort(a + 1 , a + n + 1);
        sort(b + 1 , b + m + 1);

        int i = 1 , j = 1 , ans = 0;

        while (i <= n && j <= m) 
                if (a[i] > b[j] + k) 
                        ++j;
                else 
                        if (a[i] < b[j] - k) 
                                ++i;
                        else 
                                ++i , ++j , ++ans;

        cout << ans;
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
