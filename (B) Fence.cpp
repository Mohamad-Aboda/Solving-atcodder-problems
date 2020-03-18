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

int gcd(int a, int b) {
    if (a == 0)return b;
    return gcd(b % a, a);
}

int toDec(int n) {
    int temp = n;
    int base = 1, dec = 0, last = 0;
    while (temp) {
        last = temp % 10;
        dec += last * base;
        base = base * 2;
        temp = temp / 10;
    }
    return dec;
}

bool visited[100007];
vector<int>v[100007];
void dfs(int s) {
    if (visited[s])return;
    else visited[s] = true;

    for (auto u : v[s]) {
        dfs(u);
    }
}
int arr[200007];
int cum[200007];
int main() {
    int n, k; cin >> n >> k;
    int mx = -1, res = 100000789, temp = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        cum[i] = cum[i - 1] + arr[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n- k + 1; ++i) {
        int sum = cum[(i + k-1)] - cum[(i-1)];
        //cout << sum << endl;
            if (res > sum) {
                res = sum;
                temp = i;
            }
        
    }
    cout << temp << endl;
    
            return 0;
}
