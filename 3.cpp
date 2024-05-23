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



const int M = 998244353;

int exp(int a, int n){
	int res = 1;
	while(n > 0){
		if(n & 1) res = res * a % M;
		a = a * a % M; n >>= 1;
	}
	return res;
}

void code(int TC){
	int n, h; cin >> n >> h;
	vector<pair<int, int>> x(n);
	vector<int> e(n, 2);
	for(int i = 1; i < n; i++) e[i] = e[i - 1] * 2 % M;
	for(int i = 0; i < n; i++) cin >> x[i].ff, x[i].ss = i;
	sort(x.begin(), x.end());
	vector<int> l(n), r(n), vis(n), p(n), pos(n), cl(n), cr(n);
	for(int i = 0; i < n; i++) pos[x[i].ss] = i;
	int m = 0, T = 0;
	for(int i = 0; i < n; i++){
		int c = i;
		while(i + 1 < n && x[i + 1].ff - x[i].ff <= h) i += 1;
		stack<int> s;
		for(int j = c; j <= i; j++){
			while(!s.empty() && s.top() > x[j].ss) s.pop();
			l[j] = s.size();
			s.push(x[j].ss);
			p[j] = m;
		}
		while(!s.empty()) s.pop();
		for(int j = i; j >= c; j--){
			while(!s.empty() && s.top() > x[j].ss) s.pop();
			r[j] = s.size();
			s.push(x[j].ss);
		}
		cl[c] = 1, cr[i] = 1;
		m += 1;
	}
	vector<int> a(m), f(m);
	for(int i = 0; i < n; i++){
		int id = pos[i], cur = 0, pid = p[id];
		vis[id] = 1;
		if(1 - cl[id] && 1 - cr[id] && 1 - vis[id - 1] && 1 - vis[id + 1]){
			cout << 0 << " ";
			continue;
		}
		cur = ((cl[id] || vis[id - 1]) + (cr[id] || vis[id + 1])) * exp(e[l[id] + r[id]], M - 2) % M;
		if(1 - f[pid]) f[pid] = 1, m--;
		if(m > 0){
			a[pid] = (a[pid] + cur) % M;
			cout << 0 << " ";
			continue;
		}
		else if(m == 0){
			m = -1, T = 1;
			a[pid] = (a[pid] + cur) % M;
			for(auto j : a) T = j * T % M;
		}
		else{
			T = T * exp(a[pid], M - 2) % M;
			a[pid] = (a[pid] + cur) % M;
			T = T * a[pid] % M;
		}
		cout << T * exp(a[pid], M - 2) % M * cur % M * e[n - 1] % M << " ";
	}
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