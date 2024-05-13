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
	sort(a.begin(), a.end());
	vector<int> p(n);
	for(int i = 0; i < n; i++) p[i] = p[i - (i != 0)] + a[i];
	int l = n, ans = 0;
	for(int i = 0; i < n; i++){
		while(l - 1 >= 0 && a[l - 1] + a[i] >= 1E8) l -= 1;
		int r = max(i + 1, l);
		ans = ans + (p[n - 1] - p[i]) + (n - 1 - i) * a[i] - (n - r) * (1E8);
	}
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