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
		int n; cin>>n; int a[n]; map<int,int> m;
		for(int i = 0; i<n; i++){cin>>a[i];m[a[i]];}
		int k = m.size();
		for(int i = 1; i<=n; i++){
			cout<<max(i,k)<<" ";
		}
		cout<<endl;
	}
	return 0;
}