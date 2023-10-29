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
	int n = 1410;
	map<string, int> m;
	string S = "";
	int l = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(s[0] > 60){
			S += " " + s;
			l = 1;
		}
		else{
			if(l == 1){
				m[S] += 1;
				S = "";
			}
			l = 0;
		}
	}
	int cnt = 0;
	for(auto [u, v] : m){
		if(v == 2) cout << ++cnt << ". " << u << endl;
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