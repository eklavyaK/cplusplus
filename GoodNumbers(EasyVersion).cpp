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
		int n; cin>>n; int sum = 0,s=n;
		while(sum<n){
			int temp=0,c=0; while(pow(3,temp)<s) temp++;
			for(int i = 0; i<temp; i++) c+=pow(3,i);
			if(sum+c>=n) {sum+=pow(3,temp-1);s=n-sum;}
			else sum+=pow(3,temp);
		}
		cout<<sum<<endl;
	}
	return 0;
}