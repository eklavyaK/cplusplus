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

class Trie{
	public:
	struct node{
		node* b[2];
		node(){b[0] = b[1] = NULL;}
	};
	node* head;
	Trie(){head = new node();}
	void add(int k, int bit){
		node* cur = head;
		for(int i = bit; i >= 0; i--){
			int b = ((1 << i) & k) > 0;
			if(!cur -> b[b]) cur -> b[b] = new node();
			cur = cur -> b[b];
		}
	}
	int get(int k, int bit){
		int ans = 0;
		node* cur = head;
		for(int i = bit; i >= 0; i--){
			int b = ((1 << i) & k) > 0;
			if(cur -> b[b]) cur = cur -> b[b];
			else if(cur -> b[1 - b]) cur = cur -> b[1 - b], ans += (1 << i);
			else return ans;
		}
		return ans;
	}
	void destroy(node* head){
		if(NULL != head -> b[0]) destroy(head -> b[0]);
		if(NULL != head -> b[1]) destroy(head -> b[1]);
		delete head;
	}
};

int findedge(vector<int> &a, vector<int> &b, int bit){
	if(bit < 0) return 0;
	int n = a.size(), m = b.size();
	Trie* obj = new Trie();
	for(int i = 0; i < n; i++) obj -> add(a[i], bit);
	int mn = 1 << 30;
	for(int i = 0; i < m; i++) mn = min(mn, obj -> get(b[i], bit));
	obj -> destroy(obj -> head);
	return mn;
}

int calc(vector<int> &a, int b){
	int n = a.size();
	if(n == 1) return 0;
	if(n == 2) return a[0] ^ a[1];
	vector<int> l, r;
	for(int i = 0; i < n; i++){
		if(a[i] & (1 << b)) l.push_back(a[i]);
		else r.push_back(a[i]);
	}
	int ans = 0;
	if(l.size() && b != 0) ans += calc(l, b - 1);
	if(r.size() && b != 0) ans += calc(r, b - 1);
	if(l.size() && r.size()) ans += findedge(l, r, b - 1) + (1 << b);
	return ans;
};


void code(int TC){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << calc(a, 30) << endl;
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