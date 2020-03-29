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
const int MAX = 1e6;
set<long long>prime;
void sieve()
{
    vector <int> is_prime(1000000 + 1, true);

    for (int i = 2; i <= 1e6; i++)
    {
        if (is_prime[i])
        {
            prime.insert(i * 1LL * i);

            for (int multiple = 2 * i; multiple <= 1e6; multiple += i)
                is_prime[multiple] = false;
        }
    }
}
string arr[1007];
int main() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {

        string v; cin >> v;
        if (v[0] == 'O' && v[1] == 'O' && cnt == 0) {
            v[0] = v[1] = '+';
            cnt = 1;
        }
        else if ((v[3] == 'O' && v[4] =='O' & cnt == 0)) {
            v[3] = v[4] = '+';
            cnt = 1;
        }

        arr[i] = v;
    }

    if (cnt == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    

	return 0;
}



