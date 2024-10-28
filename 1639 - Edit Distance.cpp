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

const int N = 5555;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

string a , b;
int n , m;
int dp[N][N];

void solve() {
        cin >> a >> b;

        n = a.size();
        m = b.size();

        a = " " + a;
        b = " " + b;
        dp[0][0] = 0;

        for (int i = 1 ; i <= m ; i++) dp[0][i] = i;
        for (int i = 1 ; i <= n ; i++) dp[i][0] = i;

        for (int i = 1 ; i <= n ; i++) 
                for (int j = 1 ; j <= m ; j++) {
                        int sta = (a[i] != b[j]);
                        dp[i][j] = min({dp[i - 1][j] + 1 , dp[i][j - 1] + 1 , dp[i - 1][j - 1] + sta});
                }

        cout << dp[n][m];
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