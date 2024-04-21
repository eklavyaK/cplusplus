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
	if(n & 1){
		cout << -1 << endl;
		return;
	}
	int l = 0, r = n - 1;
	vector<int> ans;
	while(l < r){
		int n = s.size();
		if(s[l] != s[r]){
			l += 1;
			r -= 1;
			continue;
		}
		if(s[l] == '0'){
			ans.push_back(r + 1);
			if(r + 1 < n) s = s.substr(0, r + 1) + "01" + s.substr(r + 1);
			else s = s.substr(0, r + 1) + "01";
			l += 1;
			r += 1;
		}
		else{
			ans.push_back(l);
			if(l != 0) s = s.substr(0, l) + "01" + s.substr(l);
			else s = "01" + s;
			l += 1;
			r -= 1;
		}
	}
	cout << (int) ans.size() << endl;
	for(auto i : ans){
		cout << i << endl;
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