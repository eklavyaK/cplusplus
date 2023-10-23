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
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++){
		a[i] = b[i] - a[i];
		if(a[i] < 0){
			cout << -1 << endl;
			return;
		}
	}
	int cnt = 0, ans = 0;
	for(int i = 0; i < n; i++){
		a[i] -= cnt;
		if(a[i] < 0){
			cout << - 1 << endl;
			return;
		}
		if(i + 1 < n && a[i + 1] - cnt > a[i]){
			cnt += a[i + 1] - cnt - a[i];
		}
	}
	ans = cnt;
	cnt = 0;
	for(int i = n - 1; i >= 0; i--){
		a[i] -= cnt;
		if(a[i] < 0){
			cout << -1 << endl;
			return;
		}
		if(i - 1 >= 0 && a[i - 1] - cnt > a[i]){
			cnt += a[i - 1] - cnt - a[i];
		}
	}
	cout << ans + cnt + a[0] << endl;
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