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


int calc(vector<int> a, vector<int> v, int n){
	int odd = 0, even = 0, cnt = 0, ans = 0, checker = 1, last = 0;
	for(int i = 0; i < n; i++){
		if(v[i] == 0) cnt += 1, ans += last;
		else{
			cnt += 1;
			if(checker) odd += cnt, ans += even * a[i], last = even * a[i];
			else even += cnt, ans += odd * a[i], last = odd * a[i];
			checker ^= 1;
		}
	}
	odd = 0, even = 0, cnt = 0, checker = 1, last = 0;
	for(int i = n - 1; i >= 0; i--){
		if(v[i] == 0) cnt += 1, ans += last;
		else{
			cnt += 1;
			if(checker) odd += cnt, ans += even * a[i], last = even * a[i];
			else even += cnt, ans += odd * a[i], last = odd * a[i];
			checker ^= 1;
			cnt = 0;
		}
	}
	return ans;
}


void code(int TC){
	int n; cin >> n;
	vector<int> a(n);
	vector<vector<int>> v(32);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		int id = 0;
		for(int j = 0; j < 32; j++){
			if((1LL << j) & a[i]) id = j;
		}
		v[id].push_back(i);
	}
	int ans = 0;
	for(int i = 0; i < 32; i++){
		vector<int> A(n), V(n);
		for(int j = 0; j < n; j++){
			if((1LL << i) & a[j]) V[j] = 1;
		}
		for(auto j : v[i]) A[j] = 1;
		ans += calc(A, V, n);
		if(i < 3) debug(ans);
	}
	cout << ans << endl;
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