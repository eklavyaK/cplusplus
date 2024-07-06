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



int calc(vector<int> &a){
	int cur = 0, mx = 0;
	debug(a);
	for(auto i : a){
		cur += i;
		if(cur < 0) cur = 0;
		else mx = max(mx, cur);
	}
	debug(mx);
	return mx;
}

void code(int TC){
	int n; cin >> n;
	vector<int> a(n + 1);
	int ans = 0, mx = 0;
	vector<int> dp(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(a[i], mx);
		if(mx == i) ans += 1, dp[i] = 1;
	}
	vector<int> cur;
	mx = 0;
	for(int i = 1; i <= n; i++){
		if(i & 1){
			if(i + 1 > n) continue;
			int c = -(dp[i] + dp[i + 1]);
			swap(a[i], a[i + 1]);
			int mx1 = max(mx, a[i]);
			int mx2 = max(mx1, a[i + 1]);
			if(mx1 == i) c += 1;
			if(mx2 == i + 1) c += 1;
			swap(a[i], a[i + 1]);
			cur.push_back(c);
		}
		mx = max(a[i], mx);
	}
	debug(ans);
	ans = max(ans, ans + calc(cur));
	cur.clear();
	mx = 0;
	for(int i = 1; i <= n; i++){
		if((i - 1) & 1){
			if(i + 1 > n) continue;
			int c = -(dp[i] + dp[i + 1]);
			swap(a[i], a[i + 1]);
			int mx1 = max(mx, a[i]);
			int mx2 = max(mx1, a[i + 1]);
			if(mx1 == i) c += 1;
			if(mx2 == i + 1) c += 1;
			swap(a[i], a[i + 1]);
			cur.push_back(c);
		}
		mx = max(a[i], mx);
	}
	ans = max(ans, ans + calc(cur));
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