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
		int a,b,p,result = 0; cin>>a>>b>>p; string s; cin>>s;
		int n = s.size(),report=n; bool detect = true;
		for(int i = n-3; i>=0; i--){
			if(s[i+1]!=s[i]){
				if(s[i+1]=='B') {
					if(result+b<=p)result+=b;
					else {detect = false;break;}
				}
				else {
					if(result+a<=p)result+=a;
					else {detect = false;break;}
				}
				report = i+2;
			}
		}
		if(detect){
			if(s[0]=='B') {
				if(result+b<=p)report=1;
			}
			else {
				if(result+a<=p)report=1;
			}
		}
		cout<<report<<endl;
	}
	return 0;
}