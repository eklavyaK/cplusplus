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
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	int ans = 0;
	vector<int> dp(m, -1E18);
	for(int i = 0; i < n; i++){
		int mn = -1E18;
		vector<int> ndp(dp.begin(), dp.end());
		for(int j = 0; j < m; j++){
			if(a[i] == b[j]){
				ans = max(ans, max(2LL, 4 + mn - i - j));
				ndp[j] = max(ndp[j], max(2 + i + j, 4 + mn));
			}
			mn = max(mn, dp[j]);
		}
		dp = ndp;
	}
	debug(dp);
	cout << ans << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}