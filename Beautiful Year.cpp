#include <bits/stdc++.h>
using namespace std;
const int mx = 16;
int arr[107];
set<int>s;

int main(){
    int n;cin >> n;
    bool ok = true;
    n++;
    while(ok){
        int a1= n %  10;
        int a2 = (n % 100)/10;
        int a3 = (n % 1000)/100;
        int a4 = (n / 1000);
        s.insert(a1);s.insert(a2);
        s.insert(a3);s.insert(a4);
        if(s.size() == 4){
            ok = false;
        }else{
            n++;
            s.clear();
        }
    }
    cout << n << endl;
	return 0;
}

