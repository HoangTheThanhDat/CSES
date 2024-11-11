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

const int maxn = 5000 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , a[maxn];
ll prefix[maxn] , dp[maxn][maxn];
bool found[maxn][maxn];

ll sum(int l , int r) {
        return prefix[r] - prefix[l - 1];
}

ll DP(int l , int r) {
        if (found[l][r]) return dp[l][r];

        found[l][r] = true;

        if (l == r) return dp[l][r] = a[l];

        return dp[l][r] = max(a[l] + sum(l + 1 , r) - DP(l + 1 , r) , a[r] + sum(l , r - 1) - DP(l , r - 1));
}

void solve() {
        cin >> n;

        prefix[0] = 0;

        for (int i = 1 ; i <= n ; i++) 
                cin >> a[i] , 
                prefix[i] = prefix[i - 1] + a[i];

        reset(found , false);

        cout << DP(1 , n) << el;
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