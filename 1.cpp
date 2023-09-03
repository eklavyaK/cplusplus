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
	vector<int> a(n), b(n - 1);
	for(int i = 0; i < n; i++) cin >> a[i];
	int sum = 0;
	for(int i = 0; i < n - 1; i++) if(!(i & 1)) sum += a[i + 1] - a[i];
	cout << ((n & 1) || (sum >= 0) ? "YES" : "NO") << endl;
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