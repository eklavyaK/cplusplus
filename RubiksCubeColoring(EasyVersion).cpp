#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n; cin>>n; long long ans = 16; if(n==1) {cout<<6<<endl;exit(0);} 
	for(int i = 3; i<=n; i++) ans = (ans*((ans*16)%1000000007))%1000000007;cout<<(ans*6)%1000000007<<endl;
	return 0;
}