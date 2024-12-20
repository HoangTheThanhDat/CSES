#include <bits/stdc++.h>

using namespace std;

int t , x , y;
long long val;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> t;

        while (t--) {
                cin >> x >> y;

                if (x >= y) 
                        if (x & 1)
                                val = 1ll * (x - 1) * (x - 1) + 1 ,
                                cout << val + (y - 1);
                        else 
                                val = 1ll * x * x ,
                                cout << val - (y - 1);
                else 
                        if (y & 1) 
                                val = 1ll * y * y , 
                                cout << val - (x - 1);
                        else 
                                val = 1ll * (y - 1) * (y - 1) + 1 ,
                                cout << val + (x - 1);    

                cout << '\n';
        }


        return 0;
}
