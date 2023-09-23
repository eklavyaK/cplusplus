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

const int N = 1E3 + 5;
vector<int> spf(N), pfac, fac, prime;
void spfac(int n){
	for(int i = 0; i <= n; i++) spf[i] = i;
	for(int i = 2; i * i <= n; i++){
		if(spf[i] != i) continue;
		for(int c = i * i; c <= n; c += i) if(spf[c] == c) spf[c] = i;
	}
	for(int i = 2; i <= n; i++) if(spf[i] == i) prime.push_back(i);
}
void primefactor(int n){
	pfac.clear();
	while(n != 1) pfac.push_back(spf[n]), n /= spf[n];
}
void allfactors(int n){
	fac.clear();
	primefactor(n);
	fac.push_back(1);
	for(int i = 0; i < pfac.size(); i++){
		n = i;
		while(i + 1 < pfac.size() && pfac[i + 1] == pfac[i]) i += 1;
		int cur = pfac[i], en = fac.size();
		for(int j = 0; j <= (i - n); j++, cur *= pfac[i]){
			for(int l = 0; l < en; l++){
				fac.push_back(fac[l] * cur);
			}
		}
	}
}

vector<int> dp(N), I(N);

void pre(){
	dp[1] = 1;
	for(int i = 2; i <= N - 5; i++){
		allfactors(i);
		dp[i] = dp[i - 1] + I[i];
		bool c = 0;
		for(auto f : fac){
			if(i == f) continue;
			int k = i / f;
			int ul = (N - 5) / f;
			for(int j = k + 1; j < k + f && j <= ul; j++){
				if(gcd(j, k) == 1) I[j * f] = 1;
			}
		}
	}
}


void code(int TC){
	int n; cin >> n;
	cout << dp[n] << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	spfac(N - 5);
	pre();
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}