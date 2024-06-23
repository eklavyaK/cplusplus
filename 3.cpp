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
	int u, v, x, y; cin >> u >> v >> x >> y;
	if((u % 2) == 0){
		if(v % 2) u -= 1;
	}
	else if(v % 2 == 0) u -= 1;
	if((x % 2) == 0){
		if(y % 2) x -= 1;
	}
	else if(y % 2 == 0) x -= 1;
	if(2 * abs(y - v) < abs(u - x)) cout << abs(y - v) + abs(2 * abs(y - v) - abs(u - x)) / 2 << endl;
	else cout << abs(y - v) << endl;
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