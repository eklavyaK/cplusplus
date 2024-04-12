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
	string s; cin >> s;
	vector<int> c(4);
	for(int i = 0; i < n; i+=2){
		if(s[i] == '1' && s[i + 1] == '0') c[3] += 1;
		if(s[i] == '1' && s[i + 1] == '1') c[2] += 1;
		if(s[i] == '0' && s[i + 1] == '0') c[1] += 1;
		if(s[i] == '0' && s[i + 1] == '1') c[0] += 1;
	}
	int ans = 0;
	if(c[3]) ans += 1, c[3] -= 1;
	ans += c[1] * 2;
	if(c[0]) ans += 2;
	ans += c[2] * 2;
	if(c[2] || c[0]) ans += c[3] > 0;
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