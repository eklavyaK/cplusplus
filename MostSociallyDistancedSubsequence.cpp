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
		int n,detect = 0; cin>>n; string s[n];
		for(int i = 0; i<n; i++){
			cin>>s[i];
		}
		for(int i = 0; i<n-1; i++){
			for(int j = 0; j<n-1; j++){
				if(s[i][j]=='1'&&s[i+1][j]=='0'&&s[i][j+1]=='0'){
					detect = 1;break;
				}
				if(detect)break;
			}
		}
		detect?cout<<"no"<<endl:cout<<"yes"<<endl;
	}
	return 0;
}