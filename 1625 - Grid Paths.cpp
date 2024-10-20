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

string s;
bool visited[10][10];

bool check(int i , int j) {
        if (visited[i][j] == true) return true;

        int cnt = 0;

        if (i - 1 > 0 && !visited[i - 1][j]) ++cnt;
        if (i + 1 < 8 && !visited[i + 1][j]) ++cnt;
        if (j - 1 > 0 && !visited[i][j - 1]) ++cnt;
        if (j + 1 < 8 && !visited[i][j + 1]) ++cnt;

        if (i == 7 && j == 1 && cnt > 0)
                return true;

        if (cnt < 2) 
                return false; 

        return true;
}

bool Check(int i , int j) {
        int col = 0 , row = 0;

        if (i - 1 > 0 && !visited[i - 1][j]) ++row;
        if (i + 1 < 8 && !visited[i + 1][j]) ++row;

        if (j - 1 > 0 && !visited[i][j - 1]) ++col;
        if (j + 1 < 8 && !visited[i][j + 1]) ++col;

        if (row == 2 && col == 0) return false;
        if (row == 0 && col == 2) return false;

        return true;
}

bool CrossCheck(int i , int j) {
        if (i - 1 > 0 && j - 1 > 0) 
                if (!check(i - 1 , j - 1)) return false;

        if (i - 1 > 0 && j + 1 < 8) 
                if (!check(i - 1 , j + 1)) return false;

        if (i + 1 < 8 && j - 1 > 0) 
                if (!check(i + 1 , j - 1)) return false;
    
        if (i + 1 < 8 && j + 1 < 8) 
                if (!check(i + 1 , j + 1)) return false;

        return true;
}

int ans = 0;

void rec(int idx , int i , int j) {
        if (visited[i][j] == true) return;

        if (i == 0 || i == 8 || j == 0 || j == 8) return;

        if (idx < 7 * 7 && i == 7 && j == 1) return;

        visited[i][j] = true;

        if (!CrossCheck(i , j)) {
                visited[i][j] = false; 

                return;
        }

        if (!Check(i , j)) {
                visited[i][j] = false;

                return;
        }

        if (idx == 7 * 7) ++ans;
        else 
                if (s[idx] == '?')
                        rec(idx + 1 , i + 1 , j) ,
                        rec(idx + 1 , i , j + 1) ,
                        rec(idx + 1 , i - 1 , j) ,
                        rec(idx + 1 , i , j - 1);
        
                else 
                        if (s[idx] == 'U') rec(idx + 1 , i - 1 , j);
                        else if (s[idx] == 'D') rec(idx + 1 , i + 1 , j);
                        else if (s[idx] == 'L') rec(idx + 1 , i , j - 1);
                        else if (s[idx] == 'R') rec(idx + 1 , i , j + 1);

        visited[i][j] = false;
}

void solve() {
        cin >> s; s = " " + s;

        reset(visited , false);

        rec(1 , 1 , 1);

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
