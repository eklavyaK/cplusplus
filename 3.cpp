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
	auto check = [&](int k){
		int l = 0, r = 0;
		for(int i = 0; i < n; i++){
			if(a[i] >= k){
				r += 1;
				continue;
			}
			l += 1;
			while(i + 1 < n && a[i + 1] < k) i += 1;
		}
		return l < r;
	};
	int l = 1, r = *max_element(a.begin(), a.end());
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	for(int i = 0; i < n; i++){
		cout << (a[i] <= l - 1 ? 1 : 0);
	}
	cout << endl;
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