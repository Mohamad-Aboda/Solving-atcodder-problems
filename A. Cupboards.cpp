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
int l0, l1, r0, r1;
int main() {
    int n; cin >> n;
   
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if (a == 0)l0++;
        if (a == 1)l1++;
        if (b == 0)r0++;
        if (b == 1)r1++;
    }
    int res = min(l0, l1) + min(r0, r1);
    cout << res << endl;
    return 0;
}
