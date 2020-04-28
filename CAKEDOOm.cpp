#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include<string>
#include <set>
#include <queue>
#include <set>
using namespace std;
char arr[11] = {'?', '1', '2', '3', '4', '5', '6' ,'7', '8', '9', '0' };
bool check(string s) {
    bool ok = true;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] != arr[i]) {
                ok = false;
                break;
            }

        }
        if (ok = false)
            break;
    }
    return ok;
}
int colors[15];
int main() {
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        string s; cin >> s;
        string ans = "NO";
        for (char c = '0'; c < '0' + k; ++c) {
            string w = s;
            if (w[0] != '?' && w[0] != c)
                continue;
            bool good = true;
            w[0] = c;
            for (int i = 1; i < s.size(); ++i) {
                bool ok = false;
                for (char d = '0'; d < '0' + k; ++d) {
                    if (w[i] != '?' && w[i] != d)
                        continue;
                    if (d != w[i - 1] && d != w[(i + 1) % (s.size())]) {
                        w[i] = d;
                        ok = true;
                        break;
                    }
                }
                if (ok == false) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans = w;
                break;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
