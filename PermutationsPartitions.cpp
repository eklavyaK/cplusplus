#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n,k,t; cin>>n>>k; int a[n]; long long result = 1l;
	int mod = 998244353;vector<int> v; map<int,int> m;
	for(int i = 0; i<n; i++) {cin>>t;m[t]=i+1;}long long sum = 0;
	for(int i = n-k+1; i<=n; i++) {v.emplace_back(m[i]);sum+=i;}
	cout<<sum<<" ";sort(v.begin(),v.end());
	for(int i = 1; i<k; i++){
		v[i-1]=v[i]-v[i-1];
	}
	for(int i = 0; i<k-1; i++)result=(result*v[i])%mod;
	cout<<result<<endl;

	return 0;
}