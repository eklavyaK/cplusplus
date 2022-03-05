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
		int a,b; cin>>a>>b;
		if(2*min(a,b)>=max(a,b) && (a+b)%3==0){cout<<"yes"<<endl;}
		else cout<<"no"<<endl;;
	}
	return 0;
}