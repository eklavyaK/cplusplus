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
	int n; cin >> n;
	vector<vector<int>> dp(n, vector<int> (n));
	vector<int> a(n), p(n);
	for(int i = 0; i < n; i++) cin >> a[i], p[i] = a[i] + p[i - (i != 0)];
	for(int i = 0; i < n; i++){
		for(int j = i; j >= 0; j--){
			if(j == i) dp[j][i] = a[i];
			else dp[j][i] = max(a[i] + (p[i - 1] - (j == 0 ? 0 : p[j - 1]) - dp[j][i - 1]), a[j] + p[i] - p[j] - dp[j + 1][i]);
		}
	}
	cout << dp[0][n - 1] << endl;
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