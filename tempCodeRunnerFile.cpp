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
	int n, x; cin >> n >> x;
	vector<int> a(n);
	int xr = 0, r = 0;
	for(int i = 0; i < n; i++) cin >> a[i], xr ^= a[i], r |= a[i];
	if(xr > x){
		cout << -1 << endl;
		return;
	}
	else if(xr < x){
		int anse = 1, anss = 1, cur = 0;
		for(int i = 32; i >= 0; i--){
			int ab = (xr >> i) & 1;
			int bb = (x >> i) & 1;
			int rb = (r >> i) & 1;
			if(ab == 1 && bb == 0){
				cout << anss << endl;
				return;
			}
			if(ab == 0 && bb == 0 && rb == 0) continue;
			if(ab == 0 && bb == 1){
				int xx = 0, cnt = 0;
				for(int i = 0; i < n; i++){
					xx ^= (a[i] & cur);
					if(xx == 0) cnt += 1;
				}
				anse = max(anse, cnt);
				cur += (1LL << i);
				xx = 0, cnt = 0;
				for(int i = 0; i < n; i++){
					xx ^= (a[i] & cur);
					if(xx == 0) cnt += 1;
				}
				anss = max(anss, cnt);
				cur -= (1LL << i);
			}
			if(ab == 0 && bb == 0 && rb == 1) cur += (1LL << i);
		}
		cout << max(anse, anss) << endl;
	}
	else{
		int ans = 0, cur = 0;
		int now = ((1LL << 35) - 1) ^ xr;
		for(int i = 0; i < n; i++){
			cur ^= (a[i] & now);
			if(cur == 0) ans += 1, cur = 0;
		}
		cout << ans << endl;
	}
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