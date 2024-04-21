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

const int N = 2E5 + 5;
int TA[N * 4], TB[N * 4], IA[N * 4], IB[N * 4];

void upda(int node, int l, int r, int pos, int c){
	if(l == r){
		TA[node] = c;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) upda(2 * node, l, mid, pos, c);
	else upda(2 * node + 1, mid + 1, r, pos, c);
	TA[node] = TA[2 * node] + TA[2 * node + 1];
}
void updb(int node, int l, int r, int pos, int c){
	if(l == r){
		TB[node] = c;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) updb(2 * node, l, mid, pos, c);
	else updb(2 * node + 1, mid + 1, r, pos, c);
	TB[node] = TB[2 * node] + TB[2 * node + 1];
}
void updIda(int node, int l, int r, int pos, int c){
	if(l == r){
		IA[node] = c;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) updIda(2 * node, l, mid, pos, c);
	else updIda(2 * node + 1, mid + 1, r, pos, c);
	IA[node] = IA[2 * node] + IA[2 * node + 1];
}
void updIdb(int node, int l, int r, int pos, int c){
	if(l == r){
		IB[node] = c;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) updIdb(2 * node, l, mid, pos, c);
	else updIdb(2 * node + 1, mid + 1, r, pos, c);
	IB[node] = IB[2 * node] + IB[2 * node + 1];
}
int qrya(int node, int l, int r, int st, int en){
	if(l > en || st > r) return 0;
	else if(st <= l && en >= r) return TA[node];
	int mid = (l + r) >> 1;
	return qrya(2 * node, l, mid, st, en) + qrya(2 * node + 1, mid + 1, r, st, en);
}
int qryb(int node, int l, int r, int st, int en){
	if(l > en || st > r) return 0;
	else if(st <= l && en >= r) return TB[node];
	int mid = (l + r) >> 1;
	return qryb(2 * node, l, mid, st, en) + qryb(2 * node + 1, mid + 1, r, st, en);
}
int qryIda(int node, int l, int r, int c, int cur){
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(cur + IA[2 * node] <= c) return qryIda(2 * node, l, mid, c, cur);
	else return qryIda(2 * node + 1, mid + 1, r, c, cur + IA[2 * node]);
}
int qryIdb(int node, int l, int r, int c, int cur){
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(cur + IB[2 * node] <= c) return qryIdb(2 * node, l, mid, c, cur);
	else return qryIdb(2 * node + 1, mid + 1, r, c, cur + IB[2 * node]);
}


void code(int TC){
	int n, C, S, M; cin >> n >> C >> S >> M;
	vector<int> a(n), b(n);
	for(int i = 0; i < 4 * n + 5; i++) TA[i] = TB[i] = IA[i] = IB[i] = 0;
	for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	int ans = n * C, cur = 0, sum = 0, k = -1, l = 0, r = 0;
	vector<int> vis(n), pA(n), pB(n);
	vector<pair<int, int>> A(n), B(n);
	for(int i = 0; i < n; i++) A[i] = B[i] = {a[i], i};
	sort(A.begin(), A.end());
	sort(b.begin(), b.end(), greater<>());
	sort(B.begin(), B.end(), greater<>());
	for(int i = 0; i < n; i++) pA[A[i].ss] = i, pB[B[i].ss] = i;
	for(int i = 0; i < n; i++){
		sum += b[i];
		cur += a[i];
		vis[i] = 1;
		updIda(1, 0, n - 1, pA[i], 1);
		updIdb(1, 0, n - 1, pB[i], 1);
		upda(1, 0, n - 1, pA[i], a[i]);
		updb(1, 0, n - 1, pB[i], a[i]);
		if(cur > M){
			ans = min(ans, i * C);
			break;
		}
		if(sum > M){
			if(k == -1){
				int now = 0;
				k = 0;
				for(int i = 0; i < n; i++){
					while(1 - vis[A[l].ss]) l += 1;
					now -= A[l].ff;
					while(vis[B[r].ss]) r += 1;
					now += B[r].ff;
					k += 1;
					if(cur + now > M) break;
				}
			}
			else{
				while(k > 1){
					auto ida = qryIda(1, 0, n - 1, k - 1, 0);
					auto idb = qryIdb(1, 0, n - 1, k - 1, 0);
					auto suma = qrya(1, 0, n - 1, 0, ida);
					auto sumb = qryb(1, 0, n - 1, 0, idb);
					if(cur + sumb - suma > M) k--;
					else break;
				}
			}
			ans = min(ans, i * C + S * k);
		}
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