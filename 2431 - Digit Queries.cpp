#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> t;

        while (t--) {
                cin >> n;

                long long pw = 1 , cs = 1;

                while (n - 9 * cs * pw > 0) {
                        n -= 9 * cs * pw;
                        ++cs;
                        pw *= 10;
                }

                long long a = pw + (n - 1) / cs;

                n %= cs;

                string so = to_string(a);

                if (n == 0) 
                        cout << so.back();
                else 
                        cout << so[n - 1];
                
                cout << '\n';
        }

        return 0;
}
