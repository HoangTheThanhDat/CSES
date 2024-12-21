#include <bits/stdc++.h>

using namespace std;

int n;

void rec(int a , int b , int c , int n) {
        if (n == 0) return;

        rec(a , c , b , n - 1);

        cout << a << " " << c << '\n';

        rec(b , a , c , n - 1);
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        cout << (1 << n) - 1 << '\n';

        rec(1 , 2 , 3 , n);

        return 0;
}
