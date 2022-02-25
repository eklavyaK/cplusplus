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
		int n,m; cin>>n>>m; int a[m],b[n]={0};
		string s; cin>>s;vector<int> v(26);
		for(int i = 0; i<m; i++)cin>>a[i];
		for(int i = 0; i<n; i++)v[s[i]-'a']++;
		sort(a,a+m);int sum = 0; for(int i = m-1; i>=0; i--){
			b[a[i]-1]=++sum;
		}
		int c = 0;
		for(int i = n-1; i>=0; i--){
			if(b[i]!=0){
				c=b[i];
			}
			v[s[i]-'a']+=c;
		}
		for(auto i : v) cout<<i<<" ";cout<<endl;
	}
	return 0;
}