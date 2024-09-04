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
	int n, k; cin >> n >> k;
	map<int, int> m;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		m[x] += 1;
	}
	vector<int> vec;
	for(auto [u, v] : m){
		vec.push_back(u);
	}
	int g = vec[0];
	for(int i = 1; i < vec.size(); i++){
		g = gcd(g, vec[i] - vec[i - 1]);
	}
	set<int> st;
	if(n == 1){
		if(k >= vec[0] + 1) cout << k << endl;
		else cout << k - 1 << endl;
	}
	else{
		if(k > (n - 1) * g - (n - 1)){
			cout << k + (n - 1) << endl;
			return;
		}
		else{
			int l = 1, r = (n - 1) * g - 1, ans = 1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(k >= mid - mid / g) l = mid + 1, ans = mid;
				else r = mid - 1;
			}
			cout << ans << endl;
		}
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