#include <bits/stdc++.h>
using namespace std;
const int mx = 16;
int arr[107];

int main(){
    int n;cin >> n;
    string ans = "NO";
    for(int i = 0; i < n; ++i){
        string handle;cin >> handle;
        int before, after;cin >> before >> after;
        if(before >= 2400 && after > before){
            ans = "YES";
        }
    }
    cout << ans << endl;
	return 0;
}

