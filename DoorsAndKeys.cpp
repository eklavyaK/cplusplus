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
        string s; cin>>s;
        if(s.find('r')>s.find('R')||s.find('g')>s.find('G')||s.find('b')>s.find('B'))
        cout<<"NO"<<endl;else cout<<"YES"<<endl;
	}
	return 0;
}