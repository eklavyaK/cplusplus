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


/*
Method of solving problems involving increasing or decreasing two adjacent elements together:

let the array be a[n] = {A1, A2, .. An}

now make a difference array b[n - 1] = {A2 - A1, A3 - A2, .. An - An - 1} = {B1, B2 .. Bn - 1}

here the problem we're solving is: we have to make the array a non - decreasing by selecting two adjacent elements and either increasing both of them by one or decreasing both of them by one. We can perform this operation any number of times

now look at the array: A1, A2, A3, A4, A5, A6 ... if we increase A3 and A4, b2 will increase and b4 will decrease simultaneously, if we decrease A3 and A4, b2 will decrease and b4 will increase. In case we increase A1 and A2 together, B2 will decrease, and if we increase An and An - 1 together Bn - 2 will increase

So conlusion is that We can increase/decrease B2 and Bn - 2 infinitely, and for other Bi can only change it (inc / dec) if we're changing either Bi - 2 or Bi + 2 with it

In order to make array a non - decreasing we have to make all the elements of B non - negative
How to do that?
                                                        _____ _____ _____
					   					     |     |     |     |           ----> these elements are connected
consider difference array b for a odd length array a: B1 B2 B3 B4 B5 B6 B7 B8
					                             	   |_____|_____|_____|
The above difference array is for odd length array a, here to make the array b non - negative we can easily just increase B1 infinitely and decrease B3 infinitely, then repeat the same procedure for B3 and B5 until B7, in the end B7 will be infinitely negative but as we know we can individually inc / dec B7 so we can make B7 non - negative
This procedure can be done for even indices where B2 can compensate for that group
											_____ _____ _____
					   					    |     |     |     |           ----> these elements are connected
consider difference array b for a odd length array a: B1 B2 B3 B4 B5 B6 B7
					                                |_____|_____|
Here we can do the same operation but only in even indices but for odd indices we have to carefully inc / dec elements because there is no element which can be increase individually. It can be easily proved that elements at odd indices can be made non - negative series of operations only if their total sum >= 0. If this condition there is alwayas exist a series of operations to make the odd indexed B's non negative
*/


void code(int TC){
	int n; cin >> n;
	vector<int> a(n), b(n - 1);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i];
	int sum = 0;
	for(int i = 0; i < n - 1; i++) if(!(i & 1)) sum += b[i];
	cout << ((n & 1) || (sum >= 0) ? "YES" : "NO") << endl;
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