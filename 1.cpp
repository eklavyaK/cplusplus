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


/* prefix function */
vector<int> y_function(string a){
	int n = a.size(), p = -1;
	vector<int> y(n, -1);
	for(int i = 1; i < n; i++){
		if(a[i] == a[p + 1]) y[i] = p += 1;
		else if(p != -1) p = y[p], i--;
	}
	return y;
}
/* returns vector of indices where b starts */
vector<int> kmp(string a, string b){
	int n = a.size(), m = b.size(), p = -1;
	vector<int> y = y_function(b), ans;
	for(int i = 0; i < n; i++){
		if(p + 1 > a.size()) break;
		if(a[i] == b[p + 1]){
			p += 1;
			if(p == m - 1) p = y[p], ans.push_back(i - m + 1);
		}
		else if(p != -1) p = y[p], i--;
	}
	return ans;
}


void code(int TC){
	

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