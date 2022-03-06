#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n; cin>>n; int a[n];long long sum = 0;
		for(int i = 0; i<n; i++)cin>>a[i];
		sort(a,a+n);for(int i = 0; i<n-1; i++) sum+=a[i];
		if(a[n-1]>sum+1) cout<<a[n-1]-sum<<endl;
		else if(a[n-1]+sum>0) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}