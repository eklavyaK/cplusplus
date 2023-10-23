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
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++){
		a[i].ff = 1 + rand() % 5;
		a[i].ss = i;
		cerr << a[i].ff << " ";
	}
	cerr << endl;
	sort(a.begin(), a.end());
	vector<int> ans(n);
	stack<int> st;
	int cur = 0;
	for(int i = 0; i < n; i++){
		while(!st.empty() && a[i].ff > cur) ans[st.top()] = cur, cur += 1, st.pop();
		cur = a[i].ff;
		ans[a[i].ss] = cur;
		cur += 1;
		int c = i;
		while(i + 1 < n && a[i + 1].ff == a[i].ff) i += 1;
		for(int j = i; j >= c + 1; j--) st.push(a[j].ss);
	}
	while(!st.empty()) ans[st.top()] = cur, cur += 1, st.pop();
	for(auto i : ans) cerr << i << " ";
	cerr << endl;
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