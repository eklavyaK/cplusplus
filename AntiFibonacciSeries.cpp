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
		int n; cin>>n;int index = n;
		for(int i = n; i>=1; i--){
			bool c=true;int track=n;
			for(int j = n; j>=1; j--){
				if(c && j==n+1-i){cout<<1<<" ";c=false;}
				else cout<<track--<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}