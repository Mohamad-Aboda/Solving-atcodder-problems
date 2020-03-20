#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
bool sortbysec(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second)return a.second > b.second;
    return a.first < b.first;
}
set<int>s;
int arr[100007];
vector<int>v;
int main() {
    int n; cin >> n;
    rep(i, n) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    //cout << s.size() << endl;
    for (auto i : s) {
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    if (s.size() == 1 || s.size() == 2) {
        cout << "YES";
    }
    else if (s.size() == 3) {
        if (v[2] - v[1] == v[1] - v[0])cout << "YES";
        else cout << "NO";
    }
else cout << "NO";
    return 0;
}
