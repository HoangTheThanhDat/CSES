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

ll a , b;

ll dp[21][10][2];

vector<int> num;

ll DP(int pos , int last_digit , bool status) {
        if (pos == num.size()) 
                return 1;

        if (dp[pos][last_digit][status] != -1) 
                return dp[pos][last_digit][status];

        ll res = 0;
        
        int limit;

        if (!status) 
                limit = num[pos];
        else 
                limit = 9;

        for (int digit = 0 ; digit <= limit ; ++digit) 
                if (digit == last_digit) continue;
                else 
                        if (!status && digit < limit) 
                                res += DP(pos + 1 , digit , !status);
                        else    
                                res += DP(pos + 1 , digit , status);

        return dp[pos][last_digit][status] = res;
}

ll get(ll n) {
        num.clear();

        while (n > 0) {
                num.push_back(n % 10);
                n /= 10;
        }

        if (num.size() == 0) num.push_back(0);

        reverse(num.begin() , num.end());

        // for (int i : num) cout << i << " "; cout << el;

        ll res = 0;

        reset(dp , -1);

        for (int i = 0 ; i < num.size() - 1 ; i++) {
                for (int digit = 1 ; digit <= 9 ; digit++) 
                        res += DP(num.size() - i , digit , true);
        }

        for (int digit = 1 ; digit <= num[0] ; ++digit)
                res += DP(1 , digit , (digit < num[0] ? true : false));

        return res;
}

void solve() {
        cin >> a >> b;

        if (a == 0) 
                cout << get(b) + 1;
        else
                cout << get(b) - get(a - 1);
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