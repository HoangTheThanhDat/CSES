#include <bits/stdc++.h>

using namespace std;

const int maxn = 8 + 2;

string chess[maxn];
bool row[maxn] , dmain[maxn + maxn] , dsecon[maxn + maxn];

long long ans = 0;

void rec(int col) {
        if (col == 9) {
                ++ans;
                return;
        }

        for (int i = 1 ; i <= 8 ; i++) 
                if (!row[i] && !dmain[i - col + 8] && !dsecon[i + col] && chess[col][i] == '.') {

                        row[i] = dmain[i - col + 8] = dsecon[i + col] = true;

                        rec(col + 1);

                        row[i] = dmain[i - col + 8] = dsecon[i + col] = false;
                }
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        for (int i = 1 ; i <= 8 ; i++) {
                cin >> chess[i];
                chess[i] = " " + chess[i];
        }

        memset(row , false , sizeof row);
        memset(dmain , false , sizeof dmain);
        memset(dsecon , false , sizeof dsecon);

        ans = 0;

        rec(1);

        cout << ans;

        return 0;
}
