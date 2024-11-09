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

const int maxn = 111;
const int maxa = 1111;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , a[maxn] , sum = 0;
bool dp[maxn * maxa];

void solve() {
        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];

                sum += a[i];
        }

        reset(dp , false); dp[0] = true;

        sort(a + 1 , a + n + 1);
        
        for (int i = 1 ; i <= n ; i++) 
                for (int j = sum ; j >= a[i] ; j--) 
                        if (!dp[j]) 
                                dp[j] = dp[j - a[i]];

        vector<int> ans;

        for (int i = 1 ; i <= sum ; i++) 
                if (dp[i]) ans.push_back(i);
        
        cout << ans.size() << el;

        for (int i : ans) cout << i << " ";
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