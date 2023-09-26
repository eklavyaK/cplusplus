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
	int A, B;
	long long a = A, b = B;
	int nt = 0, nf = 0, dt = 0, df = 0;
	long long at = a, bt = b;
	while(at % 2 == 0) at /= 2, nt += 1;
	while(at % 5 == 0) at /= 5, nf += 1;
	while(bt % 2 == 0) bt /= 2, dt += 1;
	while(bt % 2 == 0) bt /= 5, df += 1;
	if(dt > nt || df > nf){
		vector<string> ans;
		ans.push_back(to_string(a / b));
		a = a % b;
		if(a){
			ans.push_back(".");
			while(a > 0){
				while(a < b) a *= 10, ans.push_back(string(1, '0'));
				ans.push_back(string(1, 48 + a / b));
				a = a % b;
			}
		}
		string res = "";
		for(auto i : ans) res.append(i);
		return res;
	}
	else{
		vector<string> ans;
		ans.push_back(to_string(a / b));
		a = a % b;
		int c = -1;
		if(a){
			ans.push_back(".");
			vector<int> pres(10);
			while(a > 0){
				while(a < b) a *= 10, ans.push_back(string(1, '0'));
				if(pres[a / b] == 1){
					c = a / b;
					break;
				}
				else pres[a / b] = 1;
				ans.push_back(string(1, 48 + a / b));
				a = a % b;
			}
		}
		string res = "";
		for(auto i : ans){
			if(c != -1 && c != -2 && i == string(1, 48 + c)){
				c = -2;
				res.append("(");
			}
			res.append(i);
		}
		if(c == -2) res.append(")");
		return res;
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