#include <bits/stdc++.h>

using namespace std;

#define      ll      long long
#define      fi      first 
#define      se      second 
#define      el      '\n'

#define reset(__a , __v) memset(__a,__v,sizeof(__a))
#define datmacoder int32_t main()
#define opf(__dat) if (fopen(__dat".inp","r")){freopen(__dat".inp","r",stdin);freopen(__dat".out","w",stdout);}
#define openfile(__dat) opf(__dat);int _t;if(!TESTCASE)_t=1;else cin>>_t;while(_t--){solve();} 

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

const int maxm = 1000 + 68;
const int maxn = (1 << 10) + 10;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , dp[maxm][maxn];

void add(int &a , int b) {
        a += b;

        if (a >= mod) a -= mod;
}

int getbit(int n , int i) {
        return (n >> i) & 1;
}

void process(int x , int y , int mask , int next_mask) {
        if (y == n) {
                add(dp[x + 1][next_mask] , dp[x][mask]);
                return;
        }

        if (getbit(mask , y) & 1) 
                process(x , y + 1 , mask , next_mask);
        else {
                process(x , y + 1 , mask , next_mask | (1 << y));

                if (y + 1 < n && !getbit(mask , y + 1))
                        process(x , y + 2 , mask , next_mask);
        }
}

void solve() {
        cin >> n >> m;

        dp[1][0] = 1;

        for (int i = 1 ; i <= m ; i++) 
                for (int j = 0 ; j < (1 << n) ; j++) 
                        process(i , 0 , j , 0);

        cout << dp[m + 1][0];
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