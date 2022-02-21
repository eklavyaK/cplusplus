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
		long long a,b,c,d; cin>>a>>b>>c>>d;
		if(c+d<=a+b && min(a,b)>=d){
			cout<<"yes"<<endl;
		}
		else cout<<"no"<<endl;
	}
	return 0;
}