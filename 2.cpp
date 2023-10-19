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


const int N = 1e6 + 5;
vector<int> spf(N), pfac, fac, prime;
vector<int> f(N, -1);
void spfac(int n){
	for(int i = 0; i <= n; i++) spf[i] = i;
	for(int i = 2; i * i <= n; i++){
		if(spf[i] != i) continue;
		for(int c = i * i; c <= n; c += i) if(spf[c] == c) spf[c] = i;
	}
	for(int i = 2; i <= n; i++) if(spf[i] == i) prime.push_back(i);
}
void primefactor(int n){
	pfac.clear();
	int k = n;
	while(n != 1) pfac.push_back(spf[n]), n /= spf[n];
	int c = 0, sz = pfac.size();
	for(int i = 0; i < sz; i++){
		c += 1;
		while(i + 1 < sz && pfac[i + 1] == pfac[i]) i += 1;
	}
	f[k] = c;
}


void code(int TC){
	int n; cin >> n;
	vector<vector<int>> dp(n, vector<int> (n, 1E9)), vis(n, vector<int> (n)), G(n, vector<int> (n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> G[i][j];
	}
	auto check = [&](int &x, int &y){
		return x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1;
	};
	dp[0][0] = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	q.push({0, 0, 0}); 
	while(!q.empty()){
		auto [d, x, y] = q.top(); q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		if(f[G[x][y]] == -1) primefactor(G[x][y]);
		int p = f[G[x][y]], c = sqrt(G[x][y]);
		for(int i = y - p; i <= y + p; i++){
			int h = p - abs(y - i);
			for(int j = x - h; j <= x + h; j++){
				if(1 - check(i, j)) continue;
				if(dp[i][j] > dp[x][y] + c){
					dp[i][j] = dp[x][y] + c;
					q.push({dp[i][j], i, j});
				}
			}
		}
	}
	cout << dp[n - 1][n - 1] << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	spfac(N - 5);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}