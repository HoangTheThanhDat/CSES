#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const long long inf = 1e18;

int n , a[maxn];
long long prefix[maxn] , suffix[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        sort(a + 1 , a + n + 1);

        prefix[0] = 0;

        for (int i = 1 ; i <= n ; i++) prefix[i] = prefix[i - 1] + a[i];

        suffix[n + 1] = 0;

        for (int i = n ; i > 0 ; i--) suffix[i] = suffix[i + 1] + a[i];

        long long ans = inf;

        for (int i = 1 ; i <= n ; i++) {
                long long c = 0;

                c += 1ll * a[i] * (i - 1) - prefix[i - 1];
                c += suffix[i + 1] - 1ll * a[i] * (n - i);

                ans = min(ans , c);
        }

        cout << ans;

        return 0;
}
