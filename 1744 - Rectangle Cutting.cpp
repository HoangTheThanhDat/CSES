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

const int N = 555;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int a , b , dp[N][N];

void solve() {
        cin >> a >> b;

        reset(dp , inf);

        for (int i = 1 ; i <= a ; i++)  
                for (int j = 1 ; j <= b ; j++) 
                        if (i == j)
                                dp[i][j] = 0;
                        else {
                                for (int k = 1 ; k < i ; k++) 
                                        dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i - k][j] + 1);

                                for (int k = 1 ; k < j ; k++) 
                                        dp[i][j] = min(dp[i][j] , dp[i][k] + dp[i][j - k] + 1);
                        }
        
        cout << dp[a][b] << el;                        
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