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

void solve() {
    int x , n;

    cin >> x >> n;

    set<int> d = {x};

    unordered_map<int , int> mp;

    mp[x] = 1;

    set<int> up = {0 , x};
    set<int> lo = {-x , 0};

    for (int i = 0 ; i < n ; i++) {
        int y; cin >> y;

        int a = *up.upper_bound(y);
        int b = -*lo.lower_bound(-y);

        up.insert(y);
        lo.insert(-y);

        --mp[a - b];

        if (mp[a - b] == 0) {
            d.erase(a - b);
        }

        d.insert(a - y);
        d.insert(y - b);

        ++mp[a - y];
        ++mp[y - b];

        cout << *d.rbegin() << " ";
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
  H O A N G  T H E  T H A N H  D A T
*/