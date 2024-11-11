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

const int maxn = 20 + 8;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , x , w[maxn];

struct _data {
        int cnt;
        ll weight;

        friend bool operator < (const _data x , const _data y) {
                return (x.cnt < y.cnt || x.cnt == y.cnt && x.weight < y.weight);
        }

} dp[(1 << 20)];

int getbit(int n , int i) {
        return (n >> i) & 1;
}

void solve() {
        cin >> n >> x;

        for (int i = 0 ; i < n ; i++) cin >> w[i];

        dp[0].cnt = 1;
        dp[0].weight = 0;

        for (int mask = 1 ; mask < (1 << n) ; ++mask) {
                dp[mask].cnt = inf;

                for (int i = 0 ; i < n ; i++) 
                        if (getbit(mask , i) & 1) {
                                int _mask = mask ^ (1 << i);

                                _data DP;

                                if (dp[_mask].weight + w[i] <= x) 
                                        DP.cnt = dp[_mask].cnt , 
                                        DP.weight = dp[_mask].weight + w[i];
                                else 
                                        DP.cnt = dp[_mask].cnt + 1 , 
                                        DP.weight = min(dp[_mask].weight , 1ll * w[i]);

                                minimize(dp[mask] , DP);
                        }
        }
                
        cout << dp[(1 << n) - 1].cnt << el;
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