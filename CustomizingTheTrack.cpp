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
		int n; cin>>n; int a[n]; long long sum = 0l;
		for(int i = 0; i<n; i++)cin>>a[i];
		for(int i = 0; i<n; i++){
			sum+=a[i];
		}
		cout<<(n-(sum%n))*(sum%n)<<endl;
	}
	return 0;
}