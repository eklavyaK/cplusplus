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



vector<int> dx({-1, 0, 1, 0}), dy({0, -1, 0, 1});

void code(int TC){
	int n, m, K; cin >> n >> m >> K;
	int x, y; cin >> x >> y; x--, y--;
	vector<vector<int>> a(n, vector<int> (m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}
	auto check = [&](int i, int j){
		return i >= 0 && i < n && j >= 0 && j < m;
	};
	vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (210, -2E18)));
	for(int i = 0; i <= 100; i++) dp[x][y][i] = i * a[x][y];
	for(int u = 0; u <= 205; u++){
		auto ndp = dp;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k], ny = j + dy[k];
					if(check(nx, ny)){
						for(int l = 0; l <= 205; l++){
							if(dp[i][j][l] >= 0){
								ndp[nx][ny][l + 1] = max(dp[nx][ny][l + 1], max(dp[nx][ny][l] + a[nx][ny], dp[i][j][l] + a[nx][ny]));
							}
						}
					}
				}
			}
		}
		dp = ndp;
	}
	if(K <= 205){
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k <= K; k++){
					ans = max(ans, dp[i][j][k]);
				}
			}
		}
		cout << ans << endl;
	}
	else{
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k <= 205; k++){
					ans = max(ans, dp[i][j][k] + a[i][j] * (K - k));
				}
			}
		}
		cout << ans << endl;
	}
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