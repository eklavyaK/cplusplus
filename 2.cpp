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
#define debugarr(a,n) 42
#define debug(...) 42
#endif


int a[4]{0, 6, 8, 12};

int next(int dig, int inc){
     if(inc == 0) return 0;
     if(dig != 6) return dig + next((dig + dig) % 10, inc - 1);
     return (inc / 4) * 20 + a[inc % 4];
}


void code(int TC){
	int n; cin>>n;
	cerr << 2 + next(2, n) << endl;

}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}