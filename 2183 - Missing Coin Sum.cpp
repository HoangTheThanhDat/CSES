#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , a[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        sort(a + 1 , a + n + 1);

        long long sum = 1;

        for (int i = 1 ; i <= n ; i++) {
                if (a[i] > sum) {
                        cout << sum;
                        return 0;
                }

                sum += a[i];
        }

        cout << sum;

        return 0;
}
