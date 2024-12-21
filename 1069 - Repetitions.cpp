#include <bits/stdc++.h>

using namespace std;

string st;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> st;

        int ans = 1 , cnt = 1;

        for (int i = 1 ; i < st.size() ; i++) 
                if (st[i] == st[i - 1]) 
                        ++cnt;
                else {
                        ans = max(ans , cnt);
                        cnt = 1;
                }
        
        ans = max(ans , cnt);

        cout << ans;

        return 0;
}
