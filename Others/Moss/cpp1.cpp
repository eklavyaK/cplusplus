#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
#define int long long
using namespace std;

vector<int> c(60, 1);
int calc(int x, int c){
	int k = c / 2;
	int ans = (x / c) * k;
	int rem = x % c;
	if(rem >= k) ans += rem - k;
	return ans;
}

bool check(int x, int k){
	int ans = 0;
	for(int i = 0; i < 60; i++){
		if(i & 1) continue;
		ans += calc(x, c[i]);
	}
	return ans <= k;
}

int solve(int k){
	int l = 0, r = 1E17, ans = 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid, k)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return ans;
}

int main(){
	int T; cin >> T;
	for(int i = 0; i < 60;  i++) c[i] = c[i - (i != 0)] * 2;
	for(int i = 0; i < T; i++){
		int k; cin >> k;
		cout << solve(k) << endl;
	}
	return 0;
}