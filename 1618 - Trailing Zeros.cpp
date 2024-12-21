#include <bits/stdc++.h>

using namespace std;

int n;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        int ans = 0;

        while (n >= 5) n /= 5 , ans += n;

        cout << ans;

        return 0;
}
