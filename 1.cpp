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


const int inf = 1E18;

void code(int TC){
     int n, k, l = 0; cin >> n >> k;
     vector<int> a(n + 5), b(n + 5);
     for(int i = 0; i < n; i++) cin >> a[i];
     for(int i = 0; i < n; i++) cin >> b[i];
     vector<vector<vector<int>>> dp(2, vector<vector<int>> (k + 5, vector<int> (5, -inf)));
     for(int i = 0; i < n; i++){
          dp[l][1][2] = a[i] + b[i], dp[l][1][1] = -dp[l][1][2], dp[l][1][3] = a[i] - b[i], dp[l][1][4] = -dp[l][1][3];
          for(int j = 1; j <= k; j++) dp[1 - l][j][0] = dp[1 - l][j][1] = dp[1 - l][j][2] = dp[1 - l][j][3] = dp[1 - l][j][4] = -inf;
          for(int j = 1; j <= k; j++){
               dp[l][j][0] = max({dp[l][j][0], dp[l][j][1] + a[i] + b[i], dp[l][j][2] - a[i] - b[i], dp[l][j][3] + a[i] - b[i], dp[l][j][4] + b[i] - a[i]});
               dp[1 - l][j + 1][1] = max({dp[1 - l][j + 1][1], dp[l][j][1], dp[l][j][0] - b[i + 1] - a[i + 1]});
               dp[1 - l][j + 1][2] = max({dp[1 - l][j + 1][2], dp[l][j][2], dp[l][j][0] + b[i + 1] + a[i + 1]});
               dp[1 - l][j + 1][3] = max({dp[1 - l][j + 1][3], dp[l][j][3], dp[l][j][0] - b[i + 1] + a[i + 1]});
               dp[1 - l][j + 1][4] = max({dp[1 - l][j + 1][4], dp[l][j][4], dp[l][j][0] + b[i + 1] - a[i + 1]});
               dp[1 - l][j][0] = max(dp[1 - l][j][0], dp[l][j][0]);
          }
          l ^= 1;
     }
     cout << dp[1 - l][k][0] << endl;
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1; cin >> TT;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}