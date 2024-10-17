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

string s;
bool vis[7][7];

bool check(int i , int j) {
    int c = 0;

    if (vis[i][j]) return 0;

    if (i - 1 >= 0 && vis[i - 1][j] == 0) ++c;
    if (i + 1 < 7 && vis[i + 1][j] == 0) ++c;
    if (j - 1 >= 0 && vis[i][j - 1] == 0) ++c;
    if (j + 1 < 7 && vis[i][j + 1] == 0) ++c;

    if (i == 6 && j == 0 && c > 0) return 0;

    if (c < 2) 
        return 1;
    return 0;
}

bool trap(int i , int j) {
    int x = 0 , y = 0;

    if (i - 1 >= 0 && vis[i - 1][j] == 0) ++y;
    if (i + 1 < 7 && vis[i + 1][j] == 0) ++y;
    if (j - 1 >= 0 && vis[i][j - 1] == 0) ++x;
    if (j + 1 < 7 && vis[i][j + 1] == 0) ++x;

    if (x == 0 && y == 2) return true;
    if (x == 2 && y == 0) return true;

    return false;
}

int ans = 0;

void rec(int mv , int i , int j) {
    if (vis[i][j]) return;

    vis[i][j] = 1;

    int f = 0;

    if (i == 6 && j == 0) {
        if (mv == 48) ++ans;
        else {
            vis[i][j] = 0;
            ++f;
        }
    }

    if (i - 1 >= 0 && j - 1 >= 0) f += check(i - 1 , j - 1);
    if (i - 1 >= 0 && j + 1 < 7) f += check(i - 1 , j + 1);
    if (i + 1 < 7 && j + 1 < 7) f += check(i + 1 , j + 1);
    if (i + 1 < 7 && j - 1 >= 0) f += check(i + 1 , j - 1);

    f += trap(i , j);

    if (f != 0) {
        vis[i][j] = 0;
        return;
    }

    if (mv < 48) {
        if (s[mv] == '?') {
            if (i - 1 >= 0) rec(mv + 1 , i - 1 , j);
            if (i + 1 < 7) rec(mv + 1 , i + 1 , j);
            if (j - 1 >= 0) rec(mv + 1 , i , j - 1);
            if (j + 1 < 7) rec(mv + 1 , i , j + 1);
        }
        else {
            if (s[mv] == 'L' && j - 1 >= 0) rec(mv + 1 , i , j - 1);
            else if (s[mv] == 'R' && j + 1 < 7) rec(mv + 1 , i , j + 1);
            else if (s[mv] == 'U' && i - 1 >= 0) rec(mv + 1 , i - 1 , j);
            else if (s[mv] == 'D' && i + 1 < 7) rec(mv + 1 , i + 1 , j);
        }
    }

    vis[i][j] = 0;
}

void solve() {
    cin >> s;

    ans = 0;

    rec(0 , 0 , 0);

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