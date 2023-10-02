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



struct ListNode {
	int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* A, int K){
	ListNode* prev = NULL, *cur = A;
	while(cur){
		auto nex = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = nex;
	}
	return prev;
};


int code(int TC){
	vector<int> B, A;
	int n = B.size();
	int l = 0, prev = 0, rem = 0, sum = 0, ans = -1;
	for(int i = 0; i < 2 * n; i++){
		sum += A[i % n] - B[i % n];
		if(sum >= 0) l += 1;
		else l = 0, sum = 0;
		if(l == n){
			ans = i - n + 1;
			break;
		}
	}
	return ans;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		debug(code(TC));
	return 0;
}