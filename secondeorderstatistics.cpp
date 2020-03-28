#include <bits/stdc++.h>
using namespace std;
const int mx = 16;
int arr[107];
 
set<int>s;
vector<int>v;
int main(){
    int n;cin >> n;
    for(int i = 0; i < n; ++i){
        int a;cin >> a;
        if(s.count(a) == 0){
            s.insert(a);
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end());
    if(s.size() >= 2){
        cout  << v[1] << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
 
