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
		int n,k,count=0; cin>>n>>k; string s; cin>>s;
		for(int i = 0; i<n; i++){
			if(s[i]!='1'){
				int detect = 1;
				for(int j = i+1; j<min(n,i+k+1); j++){
					if(s[j]=='1'){
						detect = 0;j+=k;i=j;break;
					}
				}
				if(detect) {count++; i+=k;} 
			}
			else i+=k;
		}
		cout<<count<<endl;
	}
	return 0;
}