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
	int mn = 0, cur = 0, sum = 0, el = 0;
	for(int i = 0; i < n; i++){
		cur += a[i];
		el += 1;
		sum += a[i];
		if(cur < 0){ 
			if(el > 1) mn = min(mn, cur);
		}
		else cur = 0, el = 0;
	}
	cout << (sum - mn) + abs(mn) << endl;
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