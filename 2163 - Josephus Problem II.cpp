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

struct Data {
    int l , r , sz;
};

int n , K , c = 0 , Sqrt;
Data Block[N];
bool visited[N];


int getBlock(int i) {
    return (i - 1) / Sqrt + 1;
}

void solve() {
    cin >> n >> K;

    Sqrt = sqrt(n);

    int i = 1;

    while (i + Sqrt <= n) {
            ++c;

            Block[c].l = i;
            Block[c].r = i + Sqrt - 1;
            Block[c].sz = Sqrt;

            i += Sqrt;
    }

    if (Block[c].r < n) {
            ++c;

            Block[c].l = Block[c - 1].r + 1;
            Block[c].r = n;
            Block[c].sz = n - Block[c - 1].r;
    }

    reset(visited , false);

    int j = 0;

    i = K % n + 1;

    if (i > n) i = n;

    while (j < n) {
            int cnt = 0;

            ++j;    

            cout << i << " ";

            if (j == n) continue;

            int k = K % (n - j);

            visited[i] = true;

            int get = getBlock(i);

            --Block[get].sz;

            bool stop = false;

            for (int x = i + 1 ; x <= Block[get].r ; x++) {
                    if (!visited[x]) {
                        ++cnt;

                        if (cnt == k + 1) {
                            i = x;
                            stop = true;
                            break;
                        }
                    }
                }

            if (stop) continue;

            int x = get + 1; if (x > c) x = 1;

            while (cnt + Block[x].sz < k + 1) {
                    cnt += Block[x].sz;
            
                    ++x; if (x > c) x = 1;
                }

            for (int y = Block[x].l ; y <= Block[x].r ; y++) {
                    if (!visited[y]) {
                            ++cnt;

                            if (cnt == k + 1) {
                                    i = y;
                                    break;
                            }
                    }
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
  H O A N G  T H E  T H A N H  D A T
*/
