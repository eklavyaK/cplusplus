#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

vector<int> cur(60, 1);
long long calc(long long x, long long c){
	long long k = c / 2;
	long long ans = (x / c) * k;
	long long rem = x % c;
	if(rem >= k) ans += rem - k;
	return ans;
}

bool check(long long x, long long k){
	long long ans = 0;
	for(long long i = 0; i < 60; i++){
		if(i & 1) continue;
		ans += calc(x, cur[i]);
	}
	return ans <= k;
}

long long solve(long long k){
	long long l = 0, r = 1E17, ans = 1;
	while(l <= r){
		long long mid = (l + r) >> 1;
		if(check(mid, k)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	long long T;
	cin >> T;
	for(int i = 0; i < 60;  i++) cur[i] = cur[i - (i != 0)] * 2;
	for(int i = 0; i < T; i++){
		int k; cin >> k;
		cout << solve(k) << endl;
	}
	return 0;
}