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
	vector<int> A{11, 7, 11, 17, 12, 12, 16, 10, 11};
	int B = 4;
	int n = A.size();
	B = min(2 * B, n);
	vector<vector<long long>> dp(B + 5, vector<long long> (2, -1E9));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		vector<vector<long long>> ndp(B + 5, vector<long long> (2, -1E18));
		for(int j = 0; j <= B; j++){
			ndp[j][0] = max(dp[j][0], dp[j][1] + A[i]);
			ndp[j][1] = max(dp[j][1], dp[j][0] - A[i]);
		}
		dp = ndp;
		debug(dp);
	}
	int ans = 0;
	for(int i = 0; i <= B; i++) ans = max((long long) ans, dp[i][0]);
	cout << ans << endl;
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