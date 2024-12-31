#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , val , idx[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> val;

                idx[val] = i;
        }

        int ans = 1;

        for (int i = 2 ; i <= n ; i++) 
                if (idx[i] < idx[i - 1]) ++ans;

        cout << ans;

        return 0;
}
