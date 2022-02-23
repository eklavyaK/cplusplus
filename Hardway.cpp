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
		int x[3][2]; int in = 0,m=INT_MAX;
		for(int i = 0; i<3; i++){cin>>x[i][0]>>x[i][1];if(x[i][1]<m) {m=x[i][1];in=i;}}
		if(in==0){if(x[1][1]==x[2][1])cout<<abs(x[1][0]-x[2][0])<<endl;else cout<<0<<endl;}
		else if(in==1){if(x[0][1]==x[2][1])cout<<abs(x[0][0]-x[2][0])<<endl;else cout<<0<<endl;}
		else {if(x[0][1]==x[1][1])cout<<abs(x[0][0]-x[1][0])<<endl;else cout<<0<<endl;}
	}
	return 0;
}