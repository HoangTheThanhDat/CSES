#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define fi first 
#define se second 
#define el '\n'
#define reset(__a , __v) memset(__a,__v,sizeof(__a))
#define datmacoder int32_t main()
#define openfile(__dat) if (fopen(__dat".inp","r")){freopen(__dat".inp","r",stdin);freopen(__dat".out","w",stdout);}

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

const int N = 2 * 1e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2 * 1e9 + 1e8 + 6688;
const ll oo = 3 * 1e18 + 1e17 + 666888;
const bool TESTCASE = true;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int x , y;

void solve() {
        cin >> x >> y;

        int val;

        if (x >= y) 
                if (x & 1)
                        val = (x - 1) * (x - 1) + 1 ,
                        cout << val + (y - 1);
                else 
                        val = x * x ,
                        cout << val - (y - 1);
        else 
                if (y & 1) 
                        val = y * y , 
                        cout << val - (x - 1);
                else 
                        val = (y - 1) * (y - 1) + 1 ,
                        cout << val + (x - 1);

        cout << el;
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
