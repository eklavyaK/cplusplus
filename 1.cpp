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
#define debugarr(a,n) 42
#define debug(...) 42
#endif

int a[4]{0, 6, 8, 12};

int next(int dig, int inc){
     if(inc == 0) return 0;
     if(dig != 6) return dig + next((dig + dig) % 10, inc - 1);
     return (inc / 4) * 20 + a[inc % 4];
}


void code(int TC){
     int n, k; cin >> n >> k;
     if(n % 10 == 0){
          cout << n * k << endl;
     }
     else if(n % 10 == 5){
          cout << max(n * k, (n + 5) * (k - 1)) << endl;
     }
     else{
          int l = 0, r = k, ans = 0;
          while(l <= r){
               int mid = (l + r) >> 1;
               int n_n = (n + next(n % 10, mid)), n_m = (n + next(n % 10, mid + 4));
               if(n_n * (k - mid) >= n_m * (k - mid - 4)){
                    r = mid - 1;
                    ans = max(ans, n_n * (k - mid));
                    for(int j = 1; j < 4; j++){
                         n_n = n_n + n_n % 10;
                         ans = max(ans, n_n * (k - mid - j));
                    }
               }
               else l = mid + 1; 
          }
          cout << max(n * k, ans) << endl;
     }
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1; cin >> TT;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}