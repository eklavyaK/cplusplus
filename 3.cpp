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


struct Node{
	Node* v[2];
};
vector<Node*> T(5005);
const int K = (1 << 13);
vector<int> P(K);

void add(Node* H, int x){
	for(int i = 13; i >= 0; i--){
		bool b = (1 << i) & x;
		if(!H -> v[b]) H -> v[b] = new Node();
		H = H -> v[b];
	}
}

int calc(Node* H, int x){
	int ans = 0;
	for(int i = 13; i >= 0; i--){
		bool b = (1 << i) & x;
		if(H -> v[1 - b]) ans += (1 << i), H = H -> v[1 - b];
		else if(!H -> v[b]) return ans;
		else H = H -> v[b];
	}
	return ans;
}

void code(int TC){
	int n; cin >> n;
	vector<int> a(n);
	P.assign(K, 0); 
	for(int i = 0; i < n; i++) T[i] = new Node();
	vector<vector<int>> MEX(n, vector<int> (n));
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; i++){
		int mex = 0;
		vector<int> M(n + 5);
		vector<int> v;
		for(int j = i; j >= 0; j--){
			M[a[j]] = 1;
			while(M[mex]) mex++;
			MEX[j][i] = mex;
			ans = max(ans, mex);
			if(!P[mex]) v.push_back(mex), P[mex] = 1;
			if(j - 1 >= 0){
				int cur = calc(T[j - 1], mex);
				if(!P[cur]) v.push_back(cur), P[cur] = 1;
				ans = max(cur, ans);
			}
		}
		for(int j = 0; j < K; j++) if(P[j]) add(T[i], j);
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