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
		long long n,k; cin>>n>>k;
		long double x = -0.5 + (long double)0.5*sqrt(1+8*k);
		long long t = x;
		if(t!=x)t++;
		long long index = k-t*(t-1)/2;
		for(int i = 0; i<n-t-1; i++)cout<<'a';cout<<'b';
		for(int i = 0; i<t; i++) {if(i==t-index)cout<<'b';else cout<<'a';}
		cout<<endl;
	}
	return 0;
}