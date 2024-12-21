#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , val;
long long dp[maxn] , ans = -1e18;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> val;

                dp[i] = max(1ll * val , dp[i - 1] + val);
                
                ans = max(ans , dp[i]);
        }

        cout << ans;

        return 0;
}
