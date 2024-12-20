#include <bits/stdc++.h>

using namespace std;

int n;

long long sqr(int n) {
        return 1ll * n * n;
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) 
                cout << 1ll * sqr(i) * (sqr(i) - 1) / 2 - 4ll * (i - 1) * (i - 2) << '\n';

        return 0;
}
