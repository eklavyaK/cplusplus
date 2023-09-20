#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
Algorithm:
	1 -> 2 -> 3 -> 4 -> NULL

	start two pointers *prev (left side of gap) and *cur (right side of gap)

	initially *prev = NULL (Because there is a gap between between NULL and first node) and *cur = NULL


	steps:

					   prev   cur/A
		     NULL <- 1 <- 2       3 -> 4 -> NULL
		1. shift the *cur to next node
					   prev    A   cur
		     NULL <- 1 <- 2       3 -> 4 -> NULL		     
		2. form a bond between current node with *prev
					   prev    A  cur
		     NULL <- 1 <- 2   <-  3  4 -> NULL		
		3. make *prev as current node (A)
					    	   prev   cur/A
		     NULL <- 1 <- 2 <- 3       4 -> NULL		
		4. shift current node (A) to next node
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* A) {
	ListNode *prev = NULL, *cur = NULL;
	while(A){
		cur = A -> next;
		A -> next = prev;
		prev = A;
		A = cur;
	}
	return prev;
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