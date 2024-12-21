#include <bits/stdc++.h>

using namespace std;

const int cntlen = 'Z' - 'A' + 8;

string st , ans = "" , bw = "";
int s[cntlen];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> st;

        for (char ch : st) {
                ++s[ch - 'A'];

                if (s[ch - 'A'] % 2 == 0)
                        ans += ch;
        }

        int d = 0;

        for (int i = 'A' ; i <= 'Z' ; i++) 
                if (s[i - 'A'] & 1) {
                        ++d;

                        if (d == 2) {
                                cout << "NO SOLUTION"; 
                                return 0;
                        }

                        bw += char(i);
                }
        
        cout << ans << bw;

        reverse(ans.begin() , ans.end());

        cout << ans;

        return 0;
}
