#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

/*
Pointer is basically points to a address. If you have a pointer of a address you an access the elements of that address by just using -> or * sign.
-> sign is used if address contains more than one variable members. * sign can be used anytime
*/

struct Node{          // struct declaration and initialization
	int a;
	string b; 
	bool c;
	Node* N;

	Node(int x, string y, bool z, Node* p): a(x), b(y), c(z), N(p) {}
};

void code(int TC){

	// Note: Dont' declare two struct pointers separated using commas like - Node* a, b; // correct method is - Node *a, *b;
	
	// simple variable initilization of a struct
	// Z is a variable of Type Node and has it's own values and we access them by . operator
	Node Z(1, "HELLO", 0, NULL);

	// pointer type variable of struct
	// In this declaration we access the values of the variables using -> operator
	Node* H = new Node(10, "OK", 1, NULL);
	
	cout << Z.b << endl;
	cout << H -> b << endl;

	// we can assign the address of Z to pointer N of H
	H -> N = &Z;
	
	cout << H -> N -> b << endl;

	cout << H -> a << endl;
	// we can also move from change H pointer to N pointer
	H = H -> N;
	cout << H -> a << endl;

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