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

string arr[] = { "I hate that" ,"I love that" };
int main() {
    int n; cin >> n;
    string hate = "I hate that";
    string love = "I love that";
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            if (i == n) {
                cout << "I hate it";
            }
            else {
                cout << hate << " ";
            }
        }
        else {
            if (i == n) {
                cout << "I love it";
            }
            else {
                cout << love << " ";
            }
        }
    }
    return 0;
}
