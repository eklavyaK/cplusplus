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
	Split the lists from the middle, sort them individually, and then merge the sorted lists in sorted order
	
	Base case:
		if list is empty or it has only one node then return it as it is
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* A, ListNode* B){
    ListNode* H = B;
    while(A){
        if(B -> val > A -> val){
            swap(B -> val, A -> val);
            auto K = A -> next;
            A -> next = B -> next;
            B -> next = A;
            A = K;
            B = B -> next;
        }
        else if(B -> next) B = B -> next;
        else{
            B -> next = A;
            break;
        }
    }
    return H;
}
ListNode* sortList(ListNode* A) {
    int S = 0;
    ListNode* H = A;
    while(A) S += 1, A = A -> next;
    if(S <= 1) return H;
    int l = S / 2 - 1;
    A = H;
    while(l--) A = A -> next;
    ListNode* T = A;
    A = A -> next;
    T -> next = NULL;
    H = sortList(H); 
    A = sortList(A);
    return merge(H, A);
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