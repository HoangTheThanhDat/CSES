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

int n , k , ans = 0;
pair<int , int> a[N];
vector<int> zip;

bool cmp(pair<int , int> x , pair<int , int> y) {
        return x.se < y.se;
}

void solve() {
        cin >> n >> k;

        for (int i = 1 ; i <= n ; i++) 
                cin >> a[i].fi >> a[i].se , 
                zip.push_back(a[i].fi) ,
                zip.push_back(a[i].se);

        sort(a + 1 , a + n + 1 , cmp);
        
        sort(zip.begin() , zip.end());
        zip.resize(unique(zip.begin() , zip.end()) - zip.begin());

        for (int i = 1 ; i <= n ; i++) {
                a[i].fi = lower_bound(zip.begin() , zip.end() , a[i].fi) - zip.begin() + 1;
                a[i].se = lower_bound(zip.begin() , zip.end() , a[i].se) - zip.begin() + 1;
        }

        ans = 0;

        set<pair<int , int> , greater<pair<int , int>>> s;

        int cur = 0;

        for (int i = 1 ; i <= n ; i++) {
                set<pair<int , int> , greater<pair<int , int>>>::iterator x = s.lower_bound(make_pair(a[i].fi + 1, -1));

                if (x != s.end()) {
                        ++ans;

                        s.erase(x);
                        s.insert({a[i].se , i});
                }
                else {
                        if (cur < k) {
                                ++cur;
                                ++ans;
                                s.insert({a[i].se , i});
                        }
                }
        }

        cout << ans;
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