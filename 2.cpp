#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif





void code(int TC){
     int n, h; cin >> h >> n;
     vector<int> a(n), c(n);
     for(int i = 0; i < n; i++) cin >> a[i];
     for(int i = 0; i < n; i++) cin >> c[i];
     auto check = [&](int x){
          int sum = 0;
          for(int i = 0; i < n; i++){
               sum += (1 + (x - 1) / c[i]) * a[i];
			if(sum >= 1E18) return true;
          }
          return sum >= h;
     };
     int l = 1, r = 1E11;
     while(l <= r){
          int mid = (l + r) >> 1;
          if(check(mid)) r = mid - 1;
          else l = mid + 1;
     }
     cout << r + 1 << endl;
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     cout.precision(30);
     int TT = 1; cin >> TT;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}