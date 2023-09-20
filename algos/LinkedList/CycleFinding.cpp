#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
Let's assume we start at a node in a linked list and end up in a cycle. How to determine the node from where the cycle starts?

for ex:-
				 _________
				|         |
			    \|/        |
     1 -> 2 -> 3 -> 4 -> 5 -> 6

	there are three nodes in the cycle

To solve this we start two pointers one is fast (F) which moves with a step size of two and normal (N) pointer which moves with step size of one

Now just imagine a situation when both of these pointers in the cycle and both are moving in same direction. Now we know that F pointer will catch the N pointer at some point of time. Because velocity between them is 1, and 1 will divide any distance leaving remainder as 0. So the time required for the F pointer to catch the N pointer is the forward distance of N pointer from F pointer.

Now start both the pointers from the first node. F pointer will enter the cycle before N pointer. When N pointer enters the cycle. It'll be catched by F pointer before completing any round of the cycle.

Let's assume the distance moved into the cycle by N pointer is X, and the distance of node where cycle starts form first node is Z

Distance covered by N pointer = X + Z
Distance covered by F pointer = 2 * (X + Z)

difference between distances = X + Z = m C,       where C is the circumference of the circle and m is number of extra rounds by F pointer

Observation: 
	from this node (currently position both pointers ) if we move Z distance we'll be reaching the node where cycle starts
	
	Proof: 
	Since X + Z completes a whole number of rounds of the cycle, and X is less than the circumference of the cycle, after moving Z distance forward we'll still require X distance to complete the round and reach the same position.
	
Now observe that N pointer has moved X distance into the cycle, so the cycle starting node is X distance earlier, which can be reached again by moving another Z distance

Solution:
	Start a pointer from the first and another pointer from position where pointers are located, move until both the nodes are same.
	This particular node is the answer

*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* A) {
	ListNode* H = A;
	auto fast = A;
	auto slow = A;
	while(true){
		if(fast == NULL) return NULL;
		else if(fast -> next == NULL) return NULL;
		else if(fast -> next -> next == NULL)  return NULL;
		fast = fast -> next -> next;
		slow = slow -> next;
		if(fast == slow) break;
	}
	while(H != fast){
		H = H -> next;
		fast = fast -> next;
	}
	return H;
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