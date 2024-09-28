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


string f = "narek";
set<char> st({'n', 'a', 'r', 'e', 'k'});

void code(int TC){
	int n, m; cin >> n >> m;
	vector<pair<int, int>> dp(n);
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++){
		int id = m;
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'n'){
				id = j;
				break;
			}
		}
		int cur = 5, all = 0, tf = 0;
		for(int j = id - 1; j >= 0; j--){
			if(cur > 0 && s[i][j] == f[cur - 1]) cur -= 1;
			if(st.count(s[i][j])) all += 1;
		}
		for(int j = id; j < m; j++){
			if(st.count(s[i][j])) all += 1;
			if(f[tf % 5] == s[i][j]) tf += 1;
		}
		dp[i].ss = tf % 5;
		dp[i].ff = tf - (all - tf);
		for(int j = 0; j < i; j++){
			if(dp[j].ss >= cur) dp[i].ff = max(dp[i].ff, dp[j].ff + (5 - dp[j].ss) + tf - (all - tf - (5 - dp[j].ss)));
			else dp[i].ff = max(dp[i].ff, dp[j].ff + tf - (all - tf) - 2 * dp[j].ss);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dp[i].ff - 2 * dp[i].ss);
	}
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