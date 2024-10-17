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
const bool TESTCASE = true;

//  ------------------- d a t m a . _ c o d e r -------------------  //


vector<int> a[6];
int x , y;

void solve() {
    cin >> x >> y;

    cout << a[x][y] << el;
}

datmacoder {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    openfile("txt");

    int testcase;
    if (!TESTCASE) testcase = 1;
    else cin >> testcase;
    
    a[1] = {0 , 1 , 2 , 9 , 10 , 25};
    a[2] = {0 , 4 , 3 , 8 , 11 , 24};
    a[3] = {0 , 5 , 6 , 7 , 12 , 23};
    a[4] = {0 , 16 , 15 , 14 , 13 , 22};
    a[5] = {9 , 17 , 18 , 19 , 20 , 21};

    while (testcase--) {
        solve();
    }

    return 0;
}

/* 
  d a t m a . _ c o d e r
  H O A N G  T H E  T H A N H  D A T
*/