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
vector<pair<int, int>>v;
int n, sum;
int arr[200007];
set<int>s;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    int temp = n / 2;
    int key = sum / temp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n ; ++j) {
            if (arr[i] + arr[j] == key) {
                if (s.count(i+1) == 0 && s.count(j+1) == 0) {
                    v.push_back(make_pair(i + 1, j + 1));
                    s.insert(i + 1);
                    s.insert(j + 1);
                }
            }
        }
    }
    s.clear();
    int cnt = 0;
    for (auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
