#include <bits/stdc++.h>
using namespace std;
const int mx = 16;
int a[mx], b[1<<mx], c[1<<mx];
int main(){
  int t;cin >>t;
  while(t--){
      int n;cin >> n;
      int len = 1<<n;
      for(int i = 0; i < len; ++i){
          cin >> b[i];
      }
      sort(b, b + len);
      multiset<int>s;
    int fptr = 0, ptr = 0;

      for(int i = 1; i < len; ++i){
          int possible = -1;
          if(!s.empty()){possible = *s.begin();}
          if(possible == b[i])s.erase(s.begin());
          else{
              int temp = ptr;
              a[fptr] = b[i];
              for(int j = 0; j < temp; ++j){
                  c[ptr] = c[j] + a[fptr];
                  s.insert(c[ptr]);
                  ptr++;
              }
              c[ptr] = a[fptr];
              ptr++, fptr++;
              
          }
      }
      for(int i = 0; i < fptr; ++i){
          cout << a[i] << " ";
      }
      cout << endl;
      
  }
  
	return 0;
}

