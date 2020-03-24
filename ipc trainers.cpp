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
int main()
{
	int t;
	while (t--) {
		int n, days; cin >> n >> days;
		vector<int> sday(n), lecture(n), sadness(n);
		for (int i = 0; i < n; ++i) {
			cin >> sday[i] >> lecture[i] >> sadness[i];
			sday[i]--;
		}
		vector<pair<int, int>> person(n);
		for (int i = 0; i < n; ++i) {
			person.push_back({ sadness[i], i });
		}
		sort(person.rbegin(), person.rend());
		set<int>day_set;
		vector<int>lec_taken(n);
		for (int i = 0; i < n; ++i)day_set.insert(i);
		for (auto per : person) {
			int lec = lecture[per.second];
			for (int i = 0; i < lec; ++i) {
				auto it = day_set.lower_bound(sday[per.second]);
				if (it == day_set.end())break;
				else {
					lec_taken[per.second]++;
					day_set.erase(it);
				}
			}
		}
		int ans = 0; 
		for (int i = 0; i < n; ++i) {
			ans += (lecture[i] - lec_taken[i]) * sadness[i];
		}
		cout << ans << endl;
	}

	return 0;
}

