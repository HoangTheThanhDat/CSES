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

char chess[8][8];
int c = 0;
int ld[15] , rd[15] , row[7];

void rec(int j) {
    if (j == 8) {
        ++c;
        return;
    }

    for (int i = 0 ; i < 8 ; i++) {
        if (chess[i][j] == '.' && ld[i - j + 7] == 0 && rd[i + j] == 0 && row[i] == 0) {
            ld[i - j + 7] = 1;
            rd[i + j] = 1;
            row[i] = 1;

            rec(j + 1);

            ld[i - j + 7] = 0;
            rd[i + j] = 0;
            row[i] = 0;
        }
    }
}

void solve() {
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            cin >> chess[i][j];
        }
    }

    rec(0);

    cout << c;
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