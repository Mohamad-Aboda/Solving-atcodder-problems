#include <bits/stdc++.h>
using namespace std;
int arr[70000];
int mod(int b, int p, int m){
	if(p ==  0)return 1;
	if(p % 2 == 0){
		int sq = mod(b, p / 2, m);
		return (sq * sq) % m;
	}else
		return  ((b%m) * mod(b, p-1, m) )%m;
	
	
}
int main(){
	int b, p, m;
	while(cin >> b >> p >> m){
		cout << mod(b, p, m) << endl;
	}
	return 0;
}

