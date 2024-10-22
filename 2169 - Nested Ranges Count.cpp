#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first 
#define se second 
#define el '\n'
#define reset(__a , __v) memset(__a,__v,sizeof(__a))
#define datmacoder int32_t main()
#define openfile(__dat) if (fopen(__dat".inp","r")){freopen(__dat".inp","r",stdin);freopen(__dat".out","w",stdout);}

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

const int N = 2e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n;

struct BIT {
        int bit[2 * N];

        void update(int idx) {
                for (; idx <= 2 * n ; idx += idx & -idx) ++bit[idx];        
        }

        int get(int idx) {
                int res = 0;

                for (; idx > 0 ; idx &= idx - 1) res += bit[idx];

                return res;
        }
} fenwick;

int in[N] , out[N];
pair<pair<int , int> , int> p[N];
vector<int> pos;

bool cmp(pair<pair<int , int> , int> a , pair<pair<int , int> , int> b) {
        return (a.fi.fi == b.fi.fi ? a.fi.se > b.fi.se : a.fi.fi < b.fi.fi);
}

void solve() {
        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> p[i].fi.fi >> p[i].fi.se;
                p[i].se = i;

                pos.push_back(p[i].fi.fi);
                pos.push_back(p[i].fi.se);
        }

        sort(p + 1 , p + n + 1 , cmp);

        sort(pos.begin() , pos.end());
        pos.resize(unique(pos.begin() , pos.end()) - pos.begin());

        for (int i = 1 ; i <= n ; i++) 
                p[i].fi.fi = lower_bound(pos.begin() , pos.end() , p[i].fi.fi) - pos.begin() + 1 , 
                p[i].fi.se = lower_bound(pos.begin() , pos.end() , p[i].fi.se) - pos.begin() + 1;

        for (int i = n ; i > 0 ; i--) 
                in[p[i].se] = fenwick.get(p[i].fi.se) ,
                fenwick.update(p[i].fi.se);
        
        for (int i = 0 ; i <= 2 * n ; i++) fenwick.bit[i] = 0;

        for (int i = 1 ; i <= n ; i++) 
                out[p[i].se] = fenwick.get(2 * n) - fenwick.get(p[i].fi.se - 1) ,
                fenwick.update(p[i].fi.se);

        for (int i = 1 ; i <= n ; i++) cout << in[i] << " "; cout << el;
        for (int i = 1 ; i <= n ; i++) cout << out[i] << " ";
}

datmacoder {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        openfile("txt");

        int testcase;
        if (!TESTCASE) testcase = 1;
        else cin >> testcase;

        while (testcase--) {
                solve();
        }

        return 0;
}

/* 
        d a t m a . _ c o d e r
        H O A N G   T H E   T H A N H   D A T
*/
