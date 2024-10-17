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

const int N = 2 * 1e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2 * 1e9 + 1e8 + 6688;
const ll oo = 3 * 1e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n;

void backtraking(int a , int b , int c , int n) {
    if (n == 0) return;

    backtraking(a , c , b , n - 1);

    cout << a << " " << c << el;

    backtraking(b , a , c , n - 1);
}

void solve() {
    cin >> n;
    
    cout << (1 << n) - 1 << el;

    backtraking(1 , 2 , 3 ,  n);
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