#include<iostream>
#include<stack>
#include<string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)return a.second > b.second;
	return a.first < b.first;

}

int g[101][101], dp[101][101];
int main() {
	int t; cin >> t;
	while (t--) {
		int r, c; cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> g[i][j];

		for (int i = 0; i < c; i++)
			dp[0][i] = g[0][i];
		for (int i = 1; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int a = -1, b = -1, c = -1;
				if (j > 0) a = dp[i - 1][j - 1];
				if (j - c > 0)  b = dp[i - 1][j + 1];
				c = dp[i - 1][j];
				int res = max({ a, b, c });
				dp[i][j] = (res + g[i][j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < c; i++) {
			ans = max(ans, dp[r - 1][i]);
		}
		cout << ans << endl;
	}
	return 0;
}


