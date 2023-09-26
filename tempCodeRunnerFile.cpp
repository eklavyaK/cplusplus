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
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 2; i < n; i++){
		if(a[i] >= 0) ans += a[i];
	}
	if(n == 1){
		if(a[0] >= 0) cout << a[0] << endl;
		else cout << 0 << endl;
		return;
	}
	if(a[0] < 0 && a[1] >= 0){
		ans += max(0ll, a[1] + a[0]);
	}
	else{
		if(a[0] >= 0) ans += a[0];
		if(a[1] >= 0) ans += a[1];
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