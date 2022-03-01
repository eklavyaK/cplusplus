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
		long long n; cin>>n; 
		if(n<6) cout<<15<<endl;
		else if(n%2){
			cout<<(n+1)*5/2<<endl;
		}
		else{
			cout<<n*5/2<<endl;
		}
	}
	return 0;
}