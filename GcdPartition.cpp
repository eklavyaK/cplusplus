#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	ll sum[n+1]{};
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		sum[i] = sum[i-1]+k;
	}
	ll mx = 0;
	for(int i=1;i<n;i++){
		mx = max(gcd(sum[i],sum[n]-sum[i]),mx);
	}
	cout<<mx<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}