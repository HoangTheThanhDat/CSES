#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , a[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        long long ans = 0;

        cin >> a[1];

        for (int i = 2 ; i <= n ; i++) {
                cin >> a[i];

                if (a[i] < a[i - 1]) {
                        ans += a[i - 1] - a[i];
                        a[i] = a[i - 1];
                }
        }

        cout << ans;

        return 0;
}
