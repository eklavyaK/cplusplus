#include<bits/stdc++.h>
using namespace std;




signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		int l = 0, ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == 0){
				l = 0;
				continue;
			}
			if(l == 1 && a[i] <= 2){
				l = 0;
				continue;
			}
			if(a[i] <= 2){
				ans += 1;
				l = 1;
			}
			else{
				if(l == 1 && i != n - 1 && a[i] <= 4 && a[i + 1] <= 4){
					a[i + 1] = min(a[i + 1], 2);
				}
				ans += 1;
				l = 0;
			}
		}
		cout <<  ans << endl;
	}
}