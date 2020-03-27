#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)return a.second > b.second;
	return a.first < b.first;

}

int arr[100];
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int cnt = 0;
		float all = float((n * (n - 1)) / 2);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (gcd(arr[i], arr[j]) != 1)cnt++;
			}
		}
		//cout << cnt << endl;
		if (cnt == all) {
			cout << "No estimate for this data set." << endl;
		}
		else {
			cout << fixed << setprecision(6) << sqrt(cnt * all * 1.0 / cnt) << endl;
		}
		
	}
	return 0;
}


