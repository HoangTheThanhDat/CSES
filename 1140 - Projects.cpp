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

const int maxn = 2e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n;
pair<pair<int , int> , int> a[maxn];
set<pair<int , int> , greater<pair<int , int>>> s;
ll dp[maxn];

void solve() {
        cin >> n;

        for (int i = 1 ; i <= n ; i++) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;

        sort(a + 1 , a + n + 1 , [](pair<pair<int , int> , int> x , pair<pair<int , int> , int> y) {
                return x.fi.se < y.fi.se;
        });

        dp[0] = 1;

        for (int i = 1 ; i <= n ; i++) {
                set<pair<int , int> , greater<pair<int , int>>>::iterator x = s.lower_bound(make_pair(a[i].fi.fi - 1 , n + 1));
                
                if (x != s.end()) dp[i] = dp[x->se] + a[i].se; 
                else dp[i] = a[i].se;

                maximize(dp[i] , dp[i - 1]);

                s.insert(make_pair(a[i].fi.se , i));
        }

        cout << *max_element(dp + 1 , dp + n + 1) << el;
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