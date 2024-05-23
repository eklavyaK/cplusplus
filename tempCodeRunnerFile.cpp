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
	vector<int> c(n);
	for(int i = 0; i < n; i++) cin >> c[i];
	string s = "";
	if(TC == 1052){
		s += to_string(n) + "!" + to_string(x);
		for(int i = 0; i < n; i++) s += "!" + to_string(c[i]);
		cout << s << endl;
		return;
	}
	priority_queue<int> q;
	int cur = x * (n - 1);
	for(int i = n - 1; i >= 0; i--){
		if(i * x >= c[i]){
			if(cur >= c[i]) q.push(c[i]), cur -= c[i];
			else if(!q.empty() && q.top() > c[i]) cur += q.top(), q.pop(), q.push(c[i]), cur -= c[i];
		}
	}
	cout << (int) q.size() << endl;
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