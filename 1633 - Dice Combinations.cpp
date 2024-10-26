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

const int N = 1e6 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , dp[N];

void add(int &a , int b) {
        a += b;

        if (a >= mod) a -= mod;
}

void solve() {
        cin >> n;

        for (int i = 1 ; i <= 6 ; i++) dp[i] = 1 << (i - 1);

        for (int i = 7 ; i <= n ; i++) {
                dp[i] = 0;

                for (int j = 1 ; j <= 6 ; j++) {
                        add(dp[i] , dp[i - j]);
                }
        }

        cout << dp[n] << el;
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