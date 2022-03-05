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
		int n,x; cin>>n>>x; int a[n];
		for(int i = 0; i<n; i++) cin>>a[i];
		int m = *max_element(a,a+n), index = 0;
		if(m<=x){
			if(x%m)cout<<x/m+1<<endl;
			else cout<<x/m<<endl;
		}
		else{
		for(int i = 0; i<n; i++){
			if(a[i]==x) {index = 1;break;}
		}
		if(index)cout<<1<<endl;
		else cout<<2<<endl;
		}
	}
	return 0;
}