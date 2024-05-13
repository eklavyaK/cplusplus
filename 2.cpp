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
	int n, k, q; cin >> n >> k >> q;
	vector<int> a(k), b(k);
	for(int i = 0; i < k; i++) cin >> a[i];
	for(int i = 0; i < k; i++) cin >> b[i];
	vector<ld> s(k);
	for(int i = 0; i < k; i++){
		if(i == 0){
			s[i] = a[i] / (ld) b[i];
		}
		else{
			s[i] = (a[i] - a[i - 1]) / (ld) (b[i] - b[i - 1]);
		}
	}
	while(q--){
		int d; cin >> d;
		int id = lower_bound(a.begin(), a.end(), d) - a.begin();
		cout << (id == 0 ? 0 : b[id - 1]) + (int) ((d - (id == 0 ? 0 : a[id - 1])) / s[id]) << " ";
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