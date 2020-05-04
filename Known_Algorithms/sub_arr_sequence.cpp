#include <bits/stdc++.h>
using namespace std;
void gen_subsequence(vector<int>arr, int n){
	int size = pow(2, n);
	for(int i = 0;i < size; ++i){
		for(int j = 0; j < n ;++j){
			if(i & 1 << j){
				cout << arr[j];
			}
		}
		cout << endl;
	}
}

void gen_subarr(vector<int>arr){
	int n = arr.size();
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			for(int k = i ; k<= j; ++k){
				cout << arr[k] ;
			}
			cout << endl;
		}
	}
}

void gen_subarr_rec(vector<int>arr, int start, int end){
	if(end == arr.size())
		return;
	if(start > end){
		gen_subarr_rec(arr, 0, end + 1);
	}else{

		for(int i = start; i <= end; ++i){
			cout << arr[i];
		}
		cout << endl;
		gen_subarr_rec(arr, start + 1, end);
	}
}


int main(){
	vector<int> arr = {1, 2, 4};
	int n = 3;
	gen_subarr(arr);
	cout << "LOVE IT" << endl;
	gen_subsequence(arr, n);
	cout << "LOVE IT" << endl;
	gen_subarr_rec(arr, 0, 0);
	return 0;
}
