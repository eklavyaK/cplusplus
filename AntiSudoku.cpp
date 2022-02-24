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
		string s[9];
		for(int i = 0; i<9; i++)cin>>s[i];
		int track = 0, in = 0;
		for(int i = 0; i<9; i++){
			s[i][track] = ((s[i][track]-'0')%9+1)+48;
			if(track>=6) track = ++in; else track+=3;
		}
		for(int i = 0; i<9; i++) cout<<s[i]<<endl;
	}
	return 0;
}