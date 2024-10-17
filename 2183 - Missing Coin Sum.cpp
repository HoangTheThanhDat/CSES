#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
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

int n , a[N] , dp[N];

void solve() {
    cin >> n;

    for (int i = 1 ; i <= n ; i++) cin >> a[i];

    sort(a + 1 , a + n + 1);

    dp[0] = 1;

    for (int i = 1 ; i <= n ; i++) {
        if (dp[i - 1] < a[i]) {
            cout << dp[i - 1] << el;
            return;
        }
        
        dp[i] = dp[i - 1] + a[i];
    }

    cout << dp[n];
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