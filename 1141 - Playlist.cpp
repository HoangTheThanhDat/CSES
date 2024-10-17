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

int n , x;
pair<int , int> a[N];
set<pair<int , int>> s;
set<pair<int , int>>::iterator y;
int ans = 0 , cur = 0;

void solve() {
    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        cin >> x;

        a[i] = {x , i};
    }

    for (int i = 0 ; i < n ; i++) {
        x = a[i].fi;

        y = s.lower_bound({x , -1});

        if (y == s.end() || y -> fi > x) s.insert(a[i]);
        else {
            maximize(ans , (int)s.size());

            for (int i = cur ; i <= y -> se ; i++) {
                s.erase(a[i]);
            }

            cur = y -> se + 1;
            s.insert(a[i]);
        }
    }

    maximize(ans , (int)s.size());

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
  H O A N G  T H E  T H A N H  D A T
*/