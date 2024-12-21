#include <bits/stdc++.h>

using namespace std;

int n;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        if (n * (n + 1) / 2 & 1) 
                cout << "NO";
        else {
                set<int> a;
                set<int> b;

                int i , sta;

                if (n & 1) {
                        a.insert(1); a.insert(2);
                        b.insert(3);

                        i = 4; sta = 2;
                }
                else 
                        i = 1 , sta = 2;
                
                while (i <= n) {
                        if (sta == 1 || sta == 2) 
                                a.insert(i);
                        else 
                                b.insert(i);

                        sta = (sta + 1 == 5 ? 1 : sta + 1);
                        ++i;
                }

                cout << "YES" << '\n';

                cout << a.size() << '\n'; for (int i : a) cout << i << ' '; cout << '\n';
                cout << b.size() << '\n'; for (int i : b) cout << i << ' '; cout << '\n';       
        }

        return 0;
}
