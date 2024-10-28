#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first 
#define se second 
#define el '\n'
#define reset(__a , __v) memset(__a,__v,sizeof(__a))
#define datmacoder int32_t main()
#define opf(__dat) if (fopen(__dat".inp","r")){freopen(__dat".inp","r",stdin);freopen(__dat".out","w",stdout);}
#define openfile(__dat) opf(__dat);int _t;if(!TESTCASE)_t=1;else cin>>_t;while(_t--){solve();} 

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

const int N = 1e6 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = true;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n; 
ll dp[2][N];

void prepare() {
        n = 1e6;

        dp[0][1] = dp[1][1] = 1;

        for (int i = 2 ; i <= n ; i++) {
                dp[0][i] = dp[0][i - 1] * 4 + dp[1][i - 1]; dp[0][i] %= mod;                
                dp[1][i] = dp[1][i - 1] * 2 + dp[0][i - 1]; dp[1][i] %= mod;
        }
           
}

void solve() {
        cin >> n;

        cout << (dp[0][n] + dp[1][n]) % mod << el;
}

datmacoder {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        prepare();

        openfile("txt");

        return 0;
}

/* 
        d a t m a . _ c o d e r
        H O A N G   T H E   T H A N H   D A T
*/