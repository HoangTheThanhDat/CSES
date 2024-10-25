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

struct BIT_suffix {
        ll bit[N];

        void update(int idx , int value) {
                for (; idx > 0 ; idx &= idx - 1) bit[idx] += value;
        }

        ll get(int idx) {
                ll res = 0;

                for (; idx <= n ; idx += idx & -idx) res += bit[idx];

                return res;
        }
} suffix , _right;

struct BIT_prefix {
        ll bit[N];

        void update(int idx , int value) {
                for (; idx <= n ; idx += idx & -idx) bit[idx] += value;
        }

        ll get(int idx) {
                ll res = 0;

                for (; idx > 0 ; idx &= idx - 1) res += bit[idx];

                return res;
        }
} prefix , _left;

int k , a[N];
vector<int> zip;

void solve() {
        cin >> n >> k;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];

                zip.push_back(a[i]);
        }

        sort(zip.begin() , zip.end());
        
        for (int i = 1 ; i <= n ; i++) {
                int x = lower_bound(zip.begin() , zip.end() , a[i]) - zip.begin() + 1;

                _left.update(x , 1);
                _right.update(x , 1);
                prefix.update(x , a[i]);
                suffix.update(x , a[i]);        

                if (i > k) {
                        int y = lower_bound(zip.begin() , zip.end() , a[i - k]) - zip.begin() + 1;

                        _left.update(y , -1);
                        _right.update(y , -1);
                        prefix.update(y , -a[i - k]);
                        suffix.update(y , -a[i - k]);
                }

                if (i >= k) {
                        int l = 1 , r = n , p;

                        while (l <= r) {
                                int mid = l + r >> 1;

                                if (_right.get(mid) > k / 2) 
                                        p = mid ,
                                        l = mid + 1;
                                else
                                        r = mid - 1;
                        }

                        ll val = zip[p - 1];

                        ll ans = 0;

                        ans += val * _left.get(p - 1) - prefix.get(p - 1);
                        ans += suffix.get(p + 1) - val * _right.get(p + 1);

                        cout << ans << " ";
                }
        }
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