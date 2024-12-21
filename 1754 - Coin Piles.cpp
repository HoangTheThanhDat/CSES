#include <bits/stdc++.h>

using namespace std;

int t , a , b;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> t;

        while (t--) {
                cin >> a >> b;

                if ((2 * a - b) % 3 != 0 || (2 * a - b) < 0 || (2 * b - a) % 3 != 0 || (2 * b - a) < 0)      
                        cout << "NO" << '\n';
                else 
                        cout << "YES" << '\n';
        }

        return 0;
}
