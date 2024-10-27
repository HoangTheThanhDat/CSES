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

const int N = 1e5 + 68;
const int M = 111;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

void add(int &a , int b) {
        a += b;
        a %= mod;
}

int n , m , a[N] , dp[N][M];

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        if (a[1] == 0) 
                for (int i = 1 ; i <= m ; i++) dp[1][i] = 1;
        else 
                dp[1][a[1]] = 1;

        for (int i = 2 ; i <= n ; i++) {
                if (a[i] == 0)
                        for (int j = 1 ; j <= m ; j++) 
                                for (int k = max(0 , j - 1) ; k <= min(m , j + 1) ; k++) 
                                        add(dp[i][j] , dp[i - 1][k]);
                                
                else 
                        for (int k = max(0 , a[i] - 1) ; k <= min(m , a[i] + 1) ; k++) 
                                add(dp[i][a[i]] , dp[i - 1][k]);
        }

        int ans = 0;

        for (int i = 1 ; i <= m ; i++) add(ans , dp[n][i]);

        cout << ans << el;
}

datmacoder {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        openfile("txt");

        return 0;
}

/* 
        d a t m a . _ c o d e r
        H O A N G   T H E   T H A N H   D A T
*/