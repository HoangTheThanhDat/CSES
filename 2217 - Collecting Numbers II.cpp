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

int n , m , idx[N] , a[N] , ans , x , y , X , Y;

void solve() {
        cin >> n >> m;

        idx[0] = 0; idx[n + 1] = n + 1;

        for (int i = 1 ; i <= n ; i++) cin >> a[i], idx[a[i]] = i;

        ans = 1;

        for (int i = 1 ; i <= n ; i++) 
                if (idx[i - 1] > idx[i]) ++ans;

        for (int i = 1 ; i <= m ; i++) {
                cin >> X >> Y;

                x = a[X];
                y = a[Y];

                swap(a[X] , a[Y]);

                if (idx[x - 1] <= idx[x] && idx[x - 1] > Y) ++ans;
                if (idx[x - 1] > idx[x] && idx[x - 1] <= Y) --ans;
        
                if (idx[x] <= idx[x + 1] && Y > idx[x + 1]) ++ans;
                if (idx[x] > idx[x + 1] && Y <= idx[x + 1]) --ans;

                idx[x] = Y;

                if (idx[y - 1] <= idx[y] && idx[y - 1] > X) ++ans;
                if (idx[y - 1] > idx[y] && idx[y - 1] <= X) --ans;

                if (idx[y] <= idx[y + 1] && X > idx[y + 1]) ++ans;
                if (idx[y] > idx[y + 1] && X <= idx[y + 1]) --ans;

                idx[y] = X;

                cout << ans << el;
        }
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
        H O A N G  T H E  T H A N H  D A T
*/
