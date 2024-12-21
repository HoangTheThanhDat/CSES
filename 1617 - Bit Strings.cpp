#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        int ans = 1;

        while (n--) ans *= 2 , ans %= mod;

        cout << ans;

        return 0;
}
