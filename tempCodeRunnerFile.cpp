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
	string s; cin >> s;
	vector<int> one(k), zero(k);
	for(int i = 0; i < n; i++){
		if(s[i] == '1') one[(i + 1) % k] += 1;
		else zero[(i + 1) % k] += 1;
	}
	int o = 0, z = 0;
	for(int i = 0; i < k; i++){
		if(zero[i] == 0 && one[i] == 0) continue;
		else{
			if(one[i] == 0) o += 1E9;
			else o += zero[i];
			if(zero[i] == 0 && one[i] == 1) z += 1E9;
			else if(one[i] == 1) z += 2;
			else z += (one[i] + 1) / 2;
		}
	}
	cout << min(o , z) << endl;
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